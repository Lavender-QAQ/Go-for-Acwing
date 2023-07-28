#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn=600,inf=0x3f3f3f3f;

int g[maxn][maxn],vis[maxn],bike[maxn],d[maxn],c,n,s,m,take,back;
vector<int> pre[maxn];
vector<int> path,ans;

void dijkstra(){
    d[0]=0;
    for(int i=0;i<=n;i++){
        int t=-1;
        for(int j=0;j<=n;j++)
            if(!vis[j]&&(t==-1||d[j]<d[t]))
                t=j;
        for(int j=0;j<=n;j++){
            if(d[j]>d[t]+g[t][j]){
                d[j]=d[t]+g[t][j];
                pre[j].clear();
                pre[j].push_back(t);
            }
            else if(d[j]==d[t]+g[t][j]){
                pre[j].push_back(t);
            }
        }
        vis[t]=1;
    }
}

void dfs(int u){
    path.push_back(u);
    if(u==0){
        vector<int> v;
        for(int i=path.size()-1;i>=0;i--)
            v.push_back(path[i]);
        int t=0,b=0;
        for(auto i:v){
            if(i==0) continue;
            if(bike[i]<c){
                int sum=c-bike[i];
                b-=sum;
                if(b<0) t+=-b,b=0;
            }
            else if(bike[i]>c)
                b+=bike[i]-c;
        }
        if(t<take) ans=v,take=t,back=b;
        else if(t==take&&b<back) ans=v,back=b;
    }
    else
        for(auto x:pre[u])
            dfs(x);
    path.pop_back();
}

int main(){
    int a,b,x;
    take=back=inf;
    scanf("%d%d%d%d",&c,&n,&s,&m);
    c/=2;
    memset(g,0x3f,sizeof g);
    memset(d,0x3f,sizeof d);
    for(int i=1;i<=n;i++)
        scanf("%d",&bike[i]);
    while(m--){
        scanf("%d%d%d",&a,&b,&x);
        g[a][b]=g[b][a]=min(g[a][b],x);
    }
    dijkstra();
    dfs(s);
    printf("%d ",take);
    for(int i=0;i<ans.size();i++){
        if(i==0) printf("%d",ans[i]);
        else printf("->%d",ans[i]);
    }
    printf(" %d\n",back);
    return 0;
}