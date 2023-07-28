#include <iostream>
using namespace std;

int main(){
    int a1,a2,b1,b2,c1,c2,a=0,b=0,c=0;
    scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
    c=c1+c2;
    b+=c/29;
    c%=29;
    b+=b1+b2;
    a+=b/17;
    b%=17;
    a+=a1+a2;
    printf("%d.%d.%d\n",a,b,c);
    return 0;
}