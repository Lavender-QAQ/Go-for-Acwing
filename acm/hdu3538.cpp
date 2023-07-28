#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=20,T=1<<20;
const int inf=0x3f;

int dp[T][maxn],mp[maxn][maxn],n,m;

int main(){
    while(~scanf("%d%d",&n,&m)){
        n++;
        memset(dp,inf,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&mp[i][j]);
        dp[1][0]=0;
        for(int i=1;i<(1<<n);i++)
            for(int j=0;j<n;j++)
                if(i>>j&1)
                    for(int k=0;k<n;k++)
                        if((i-(1<<j))>>k&1)
                            dp[i][j]=min(dp[i][j],dp[i-(1<<j)][k]+mp[k][j]);
        printf("%d\n",dp[(1<<n)-1][m]);
    }
    return 0;
}