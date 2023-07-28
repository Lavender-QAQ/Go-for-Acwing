#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn=(int)1e6+10;

int block,num,l[maxn],r[maxn],belong[maxn],a[maxn],b[maxn],add[maxn];
int n,m;

int binary(int x,int w){
    int ll=l[x],rr=r[x],mid;
    while(ll<=rr){
        mid=(ll+rr)/2;
        if(b[mid]<w) ll=mid+1;
        else rr=mid-1;
    }
    return r[x]-ll+1;
}

void build(){
    block=(int)sqrt(n)*2;
    num=n/block;
    if(n%block)
        num++;
    for(int i=1;i<=num;i++)
        l[i]=(i-1)*block+1,r[i]=i*block;
    for(int i=1;i<=n;i++)
        belong[i]=(i-1)/block+1;
    for(int i=1;i<=num;i++)
        sort(b+l[i],b+r[i]+1);
}

void update(int left,int right,int val){
    if(belong[left]==belong[right]){
        for(int i=left;i<=right;i++)
            a[i]+=val;
        for(int i=l[belong[left]];i<=r[belong[left]];i++)
            b[i]=a[i];
        sort(b+l[belong[left]],b+r[belong[right]]+1);
    }
    else{
        for(int i=left;i<=r[belong[left]];i++)
            a[i]+=val;
        for(int i=l[belong[left]];i<=r[belong[left]];i++)
            b[i]=a[i];
        sort(b+l[belong[left]],b+r[belong[left]]+1);

        for(int i=belong[left]+1;i<=belong[right]-1;i++)
            add[belong[i]]+=val;

        for(int i=l[belong[right]];i<=right;i++)
            a[i]+=val;
        for(int i=l[belong[right]];i<=r[belong[right]];i++)
            b[i]=a[i];
        sort(b+l[belong[right]],b+r[belong[right]]+1);
    }
}

int ask(int left,int right,int val){
    int count=0;
    if(belong[left]==belong[right]) {
        for(int i=left;i<=right;i++)
            if(a[i]+add[belong[i]]>=val)
                count++;
    }
    else{
        for(int i=left;i<=r[belong[left]];i++)
            if(a[i]+add[belong[i]]>=val)
                count++;
        for(int i=belong[left]+1;i<=belong[right]-1;i++)
            count+=binary(i,val-add[belong[i]]);
        for(int i=l[belong[right]];i<=right;i++)
            if(a[i]+add[belong[i]]>=val)
                count++;
    }
    return count;
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), b[i] = a[i];
        build();
        char ch[3];
        int left, right, val;
        while (m--) {
            scanf("%s%d%d%d", ch, &left, &right, &val);
            if (ch[0] == 'M')
                update(left, right, val);
            else if (ch[0] == 'A')
                printf("%d\n", ask(left, right, val));
        }
        return 0;
    }
}