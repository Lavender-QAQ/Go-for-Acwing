#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=200010;
typedef long long ll;

struct Seq{
    int s,e,d;
}s[maxn];

int n;

ll sum(int x){
    ll ans=0;
    for(int i=0;i<n;i++)
        if(x>=s[i].s)
            ans+=(min(s[i].e,x)-s[i].s)/s[i].d+1;
    return ans;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int l=0,r=0;
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&s[i].s,&s[i].e,&s[i].d),r=max(r,s[i].e);
        while(l<r){
            int mid=(l+r)>>1;
            if(sum(mid)&1)
                r=mid;
            else
                l=mid+1;
        }
        ll ans=sum(l)-sum(l-1);
        if(ans&1)
            printf("%d %lld\n",l,ans);
        else
            printf("There's no weakness.\n");
    }
    return 0;
}