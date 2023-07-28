#include <iostream>
#include <algorithm>
#include <cstring>
#define INF (long long)1e11
using namespace std;
const int maxn = 1010;
typedef long long ll;

ll dp[maxn][maxn],s[maxn],t[maxn];
int T,S,D;

int main(){
    ios::sync_with_stdio(false);
    while(cin>>T>>S>>D){
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        int a,b;
        ll val;
        for(int i=1;i<maxn;i++)
            for(int j=1;j<maxn;j++)
                if(i==j)
                    dp[i][j]=0;
                else
                    dp[i][j]=INF;
        int city=-1;
        for(int i=1;i<=T;i++){
            cin>>a>>b>>val;
            dp[a][b]=min(dp[a][b],val);
            dp[b][a]=min(dp[b][a],val);
            city=max(max(a,b),city);
        }
        for(int k=1;k<=city;k++){
            for(int i=1;i<=city;i++){
                if(dp[i][k]!=INF)
                    for(int j=1;j<=city;j++){
                        dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
                    }
            }
        }
        for(int i=1;i<=S;i++) cin>>s[i];
        for(int i=1;i<=D;i++) cin>>t[i];
        ll mi=(ll) 1e11;
        for(int i=1;i<=S;i++){
            for(int j=1;j<=D;j++){
                mi=min(mi,dp[s[i]][t[j]]);
            }
        }
        cout << mi << endl;
    }
    return 0;
}
