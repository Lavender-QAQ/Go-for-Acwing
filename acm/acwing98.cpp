#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

P cal(ll n,ll m){
    if(n==0) return make_pair(0,0);
    ll len=1ll<<(n-1),cnt=1ll<<(2*n-2);
    P pos=cal(n-1,m%cnt);
    ll x=pos.first,y=pos.second,z=m/cnt;
    if(z==0) return make_pair(y,x);
    else if(z==1) return make_pair(x,y+len);
    else if(z==2) return make_pair(x+len,y+len);
    else if(z==3) return make_pair(2*len-1-y,len-1-x);
}

int main(){
    ll T,n,a,b;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&a,&b);
        P x=cal(n,a-1);
        P y=cal(n,b-1);
        //printf("%lld  %lld\n",x.first,x.second);
        //printf("%lld  %lld\n",y.first,y.second);
        double l1=abs(x.first-y.first),l2=abs(x.second-y.second);
        printf("%.0lf\n",sqrt(l1*l1+l2*l2)*10);
    }
    return 0;
}