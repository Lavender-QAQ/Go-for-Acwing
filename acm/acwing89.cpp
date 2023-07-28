#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll a,b,p;

ll pow_mod(ll a,ll b,ll p){
    ll ans=1;
    if(b==0)
        return 1%p;
    while(b){
        if(b&1){
            ans*=a;
            ans%=p;
        }
        a*=a;
        a%=p;
        b>>=1;
    }
    return ans%p;
}

int main(){
    while(scanf("%lld%lld%lld",&a,&b,&p)!=EOF){
        printf("%lld",pow_mod(a,b,p));
    }
    return 0;
}