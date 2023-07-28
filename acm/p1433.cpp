#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=20;
const int inf=0x3f;
typedef pair<double,double> P;

int n;
P a[maxn];
double dp[1<<20][maxn];

double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
    while(scanf("%d",&n)!=EOF){
        memset(dp,inf,sizeof(dp));
        a[0].first=a[0].second=0;
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&a[i].first,&a[i].second);
        n++;
        for(int i=0;i<n;i++)
            dp[1][i]=0;
        for(int i=1;i<(1<<n);i++)
            for(int j=0;j<n;j++)
                if(i>>j&1)
                    for(int k=0;k<n;k++)
                        if((i-(1<<j))>>k&1)
                            dp[i][j]=min(dp[i][j],dp[i-(1<<j)][k]+
                            dist(a[j].first,a[j].second,a[k].first,a[k].second));
        printf("%.2lf\n",dp[(1<<n)-1][n-1]);
    }
    return 0;
}