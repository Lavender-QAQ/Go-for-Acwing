#include <iostream>
#include <cstdio>
using namespace std;
const int mod=9901;

int a,b;

int pow_mod(int a,int b,int p){
    int ans=1%p;
    while(b){
        if(b&1){
            ans*=a;
            ans%=p;
        }
        a*=a;
        a%=p;
        b>>=1;
    }
    return ans;
}

int sum(int p,int k){
    if(k==0)
        return 1;
    if(k%2==0)
        return sum(p,k-1)+pow_mod(p,k,mod);
    else
        return sum(p,k/2)*(1+pow_mod(p,k/2+1,mod))%mod;
}

int main(){
    while(~scanf("%d%d",&a,&b)){
        int ans=1;
        for(int i=2;i<=a;i++){
            int cnt=0;
            while(a%i==0){
                cnt++;
                a/=i;
            }
            if(cnt)
                ans=ans*sum(i,cnt*b)%mod;
        }
        if(a==0) ans=0;
        printf("%d\n",ans);
    }
    return 0;
}