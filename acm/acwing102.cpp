#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=100010;
const double eps=1e-5;

int n,f;
double a[maxn];
double sum[maxn];

int main(){
    while(~scanf("%d%d",&n,&f)){
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
            scanf("%lf",&a[i]);
        double l=1,r=2000;
        while(r-l>eps){
            double mid=(l+r)/2;
            for(int i=1;i<=n;i++)
                sum[i]=a[i]-mid;
            for(int i=1;i<=n;i++)
                sum[i]+=sum[i-1];
            double mi=sum[0],ans=-1e10;
            for(int i=0,j=f;j<=n;i++,j++){
                mi=min(mi,sum[i]);
                ans=max(ans,sum[j]-mi);
            }
            if(ans>=0)
                l=mid;
            else
                r=mid;
        }
        printf("%d\n",(int)(r*1000));
    }
    return 0;
}
