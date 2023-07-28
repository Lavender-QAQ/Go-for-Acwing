#include <iostream>
using namespace std;

int main(){
    int n,x=1,l,pos,r,sum=0;
    scanf("%d",&n);
    while(n/x){
        pos=n/x%10,l=n/x/10,r=n%x;
        //printf("%d %d %d\n",l,pos,r);
        if(pos==0) sum+=l*x;
        else if(pos==1) sum+=l*x+r+1;
        else if(pos>1) sum+=(l+1)*x;
        x*=10;
    }
    printf("%d\n",sum);
    return 0;
}