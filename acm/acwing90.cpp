#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll a,b,p;

ll cal(ll a,ll b,ll p){
    ll ans=0;
    if(b==0)
        return 0;
    while(b){
        if(b&1){
            ans+=a;
            ans%=p;
        }
        a+=a;a%=p;
        b>>=1;
    }
    return ans;
}

int main(){
    while(~scanf("%lld%lld%lld",&a,&b,&p)){
        printf("%lld\n",cal(a,b,p));
    }
    return 0;
}