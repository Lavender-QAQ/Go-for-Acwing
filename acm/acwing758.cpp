#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+10;

int n,dp[maxn][2],color[maxn];
vector<int> g[maxn];

void dfs(int u){
    
}

int main(){
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        memset(color,0,sizeof(color));
        for(int i=0;i<maxn;i++) g[i].clear();
        int in;
        for(int i=1;i<n;i++){
            scanf("%d",&in);
            g[in].push_back(i);
        }
        for(int i=0;i<n;i++)
            scanf("%d",&color[i]);
        dfs(0);
    }
    return 0;
}