#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=1000010;
typedef long long ll;

ll a[maxn];
int n;

int main(){
    ll avg=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),avg+=a[i];
    avg/=n;
    for(int i=n;i>1;i--)
        a[i]=a[i+1]+avg-a[i];
    ll ans=0;
    a[1]=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        ans+=abs(a[i]-a[(n+1)/2]);
    printf("%lld\n",ans);
    return 0;
}