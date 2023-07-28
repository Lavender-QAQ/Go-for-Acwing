#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m)){
        double *dp=new double[n+10];
        memset(dp,0,sizeof(dp)*(n+10));
        int *c=new int[m+10];
        double *w=new double[m+10];
        for(int i=1;i<=m;i++)
            scanf("%d%lf",&c[i],&w[i]);
        for(int i=1;i<=m;i++){
            for(int j=n;j>=c[i];j--){
                dp[j]=max(dp[j],1-(1-w[i])*(1-dp[j-c[i]]));
            }
        }
        printf("%.1lf%%\n",dp[n]*100);
    }
    return 0;
}
