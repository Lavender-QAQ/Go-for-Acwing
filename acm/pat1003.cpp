#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=510,inf=0x3f3f3f3f;

int g[maxn][maxn],vis[maxn],d[maxn],cnt[maxn],man[maxn],sum[maxn],n,m,st,ed;

void dijkstra(){
    d[st]=0;
    sum[st]=1;
    cnt[st]=man[st];
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=0;j<n;j++)
            if(!vis[j]&&(t==-1||d[j]<d[t]))
                t=j;
        vis[t]=1;
        for(int j=0;j<n;j++){
            if(d[j]>d[t]+g[t][j]){
                d[j]=d[t]+g[t][j];
                sum[j]=sum[t];
                cnt[j]=cnt[t]+man[j];
            }
            else if(d[j]==d[t]+g[t][j]){
                cnt[j]=max(cnt[j],cnt[t]+man[j]);
                sum[j]+=sum[t];
            }
        }
    }
}

int main(){
    int a,b,c;
    memset(d,0x3f,sizeof d);
    memset(g,0x3f,sizeof g);
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    for(int i=0;i<n;i++)
        scanf("%d",&man[i]);
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    dijkstra();
    printf("%d %d\n",sum[ed],cnt[ed]);
    return 0;
}