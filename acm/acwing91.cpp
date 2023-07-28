#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int inf=0x3f;
const int maxn=20;

int dp[1<<20][maxn],mp[maxn][maxn],n;

int main(){
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&mp[i][j]);
        memset(dp,inf,sizeof(dp));
        dp[1][0]=0;
        for(int i=1;i<(1<<n);i++)
            for(int j=0;j<n;j++)
                if((i>>j)&1)
                    for(int k=0;k<n;k++)
                        if((i-(1<<j))>>k&1)
                            dp[i][j]=min(dp[i][j],dp[i-(1<<j)][k]+mp[k][j]);
        printf("%d\n",dp[(1<<n)-1][n-1]);
    }
    return 0;
}