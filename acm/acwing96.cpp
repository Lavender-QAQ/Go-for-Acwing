#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int inf=0x3f;

int three[20],four[20];

int main(){
    memset(three,inf,sizeof(three));
    memset(four,inf,sizeof(four));
    three[1]=1;
    for(int i=2;i<=12;i++)
        three[i]=three[i-1]*2+1;
    four[0]=0;four[1]=1;
    for(int i=1;i<=12;i++)
        for(int j=0;j<=i;j++)
            four[i]=min(four[i],four[j]*2+three[i-j]);
    for(int i=1;i<=12;i++)
        printf("%d\n",four[i]);
    return 0;
}