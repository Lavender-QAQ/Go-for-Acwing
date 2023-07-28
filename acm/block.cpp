
#include <linux/module.h>

#include <linux/init.h>

#include <linux/fs.h>

#include <asm/uaccess.h>

#include <linux/wait.h>

#include <linux/semaphore.h>

#include <linux/sched.h>

#include <linux/cdev.h>

#include <linux/types.h>

#include <linux/kdev_t.h>

#include <linux/device.h>


#define MAXNUM 100

#define MAJOR_NUM 456


struct dev {

    struct cdev devm;

    struct semaphore sem;

    wait_queue_head_t outq;

    int flag;

    char buffer[MAXNUM + 1];

    char *rd, *wr, *end;

} globalvar;

static struct class *my_class;

int major = MAJOR_NUM;


static ssize_t globalvar_read(struct file *, char *, size_t, loff_t *);

static ssize_t globalvar_write(struct file *, const char *, size_t, loff_t *);

static int globalvar_open(struct inode *inode, struct file *filp);

static int globalvar_release(struct inode *inode, struct file *filp);


struct file_operations globalvar_fops =

        {

                .read=globalvar_read,

                .write=globalvar_write,

                .open=globalvar_open,

                .release=globalvar_release,

        };


static int globalvar_init(void) {


    int result = 0;

    int err = 0;


    dev_t dev = MKDEV(major, 0);

    if (major) {

        result = register_chrdev_region(dev, 1, "charmem");

    } else {

        result = alloc_chrdev_region(&dev, 0, 1, "charmem");

        major = MAJOR(dev);

    }

    if (result < 0)

        return result;

    cdev_init(&globalvar.devm, &globalvar_fops);

    globalvar.devm.owner = THIS_MODULE;

    err = cdev_add(&globalvar.devm, dev, 1);

    if (err)

        printk(KERN_INFO
    "Error %d adding char_mem device", err);

    else

    {
        printk("globalvar register success\n");
        sema_init(&globalvar.sem, 1);
        init_waitqueue_head(&globalvar.outq);
        globalvar.rd = globalvar.buffer;
        globalvar.wr = globalvar.buffer;
        globalvar.end = globalvar.buffer + MAXNUM;
        globalvar.flag = 0;
    }


    my_class = class_create(THIS_MODULE, "chardev0");
    device_create(my_class, NULL, dev, NULL, "chardev0");
    return 0;

}


static int globalvar_open(struct inode *inode, struct file *filp) {

    try_module_get(THIS_MODULE);
    printk("This chrdev is in open\n");
    return (0);

}


static int globalvar_release(struct inode *inode, struct file *filp) {
    module_put(THIS_MODULE);
    printk("This chrdev is in release\n");
    return (0);
}

static void globalvar_exit(void) {

    device_destroy(my_class, MKDEV(major, 0));

    class_destroy(my_class);

    cdev_del(&globalvar.devm);

    unregister_chrdev_region(MKDEV(major, 0), 1);

}


static ssize_t globalvar_read(struct file *filp, char *buf, size_t len, loff_t *off) {

    if (wait_event_interruptible(globalvar.outq, globalvar.flag != 0)) {

        return -ERESTARTSYS;

    }


    if (down_interruptible(&globalvar.sem)) {

        return -ERESTARTSYS;

    }

    globalvar.flag = 0;

    printk("into the read function\n");

    printk("the rd is %c\n", *globalvar.rd);

    if (globalvar.rd < globalvar.wr)

        len = min(len, (size_t)(globalvar.wr - globalvar.rd));

    else

        len = min(len, (size_t)(globalvar.end - globalvar.rd));

    printk("the len is %d\n", len);


    if (copy_to_user(buf, globalvar.rd, len)) {

        printk(KERN_ALERT
        "copy failed\n");

        up(&globalvar.sem);

        return -EFAULT;

    }

    printk("the read buffer is %s\n", globalvar.buffer);

    globalvar.rd = globalvar.rd + len;

    if (globalvar.rd == globalvar.end)

        globalvar.rd = globalvar.buffer;

    up(&globalvar.sem);

    return len;

}

static ssize_t globalvar_write(struct file *filp, const char *buf, size_t len, loff_t *off) {

    if (down_interruptible(&globalvar.sem)) {

        return -ERESTARTSYS;

    }

    if (globalvar.rd <= globalvar.wr)

        len = min(len, (size_t)(globalvar.end - globalvar.wr));

    else

        len = min(len, (size_t)(globalvar.rd - globalvar.wr - 1));

    printk("the write len is %d\n", len);

    if (copy_from_user(globalvar.wr, buf, len)) {

        up(&globalvar.sem);

        return -EFAULT;

    }

    printk("the write buffer is %s\n", globalvar.buffer);

    printk("the len of buffer is %d\n", strlen(globalvar.buffer));

    globalvar.wr = globalvar.wr + len;

    if (globalvar.wr == globalvar.end)

        globalvar.wr = globalvar.buffer;

    up(&globalvar.sem);

    globalvar.flag = 1;

    wake_up_interruptible(&globalvar.outq);

    return len;

}

module_init(globalvar_init);

module_exit(globalvar_exit);

MODULE_LICENSE("GPL");


#include<sys/types.h>

#include<unistd.h>

#include<sys/stat.h>

#include<stdio.h>

#include<fcntl.h>

#include<string.h>

int main() {

    int fd;

    char msg[100];

    fd = open("/dev/chardev0", O_RDWR, S_IRUSR | S_IWUSR);

    if (fd != -1) {

        while (1) {

            printf("Please input the globar:\n");

            scanf("%s", msg);

            write(fd, msg, strlen(msg));

            if (strcmp(msg, "quit") == 0) {

                close(fd);

                break;

            }

        }

    } else {

        printf("device open failure\n");

    }

    return 0;

}


#include<sys/types.h>

#include<unistd.h>

#include<sys/stat.h>

#include<stdio.h>

#include<fcntl.h>

#include<string.h>

int main() {

    int fd, i;

    char msg[101];

    fd = open("/dev/chardev0", O_RDWR, S_IRUSR | S_IWUSR);

    if (fd != -1) {

        while (1) {

            for (i = 0; i < 101; i++)

                msg[i] = '\0';

            read(fd, msg, 100);

            printf("%s\n", msg);

            if (strcmp(msg, "quit") == 0) {

                close(fd);

                break;

            }

        }

    } else {

        printf("device open failure,%d\n", fd);

    }

    return 0;

}


PWD = $(shell
pwd)

KERNEL_SRC =
/usr/src/kernels/linux-2.6.38/



obj-m := chat.
o

        module
-objs := chat.
o

        all
:

$(MAKE)
-
C $(KERNEL_SRC)
M = $(PWD)
modules

        clean
:

rm *.
ko

        rm
*.o


