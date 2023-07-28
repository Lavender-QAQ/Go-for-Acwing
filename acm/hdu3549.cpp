#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1010;
const int inf=1<<30;

struct edge{
    int v,f,nxt;
}e[maxn<<1];

int num,n,m,s,t,g[maxn];
queue<int> que;
int vis[maxn],d[maxn];

void addedge(int u,int v,int val){
    e[++num].v=v;
    e[num].f=val;
    e[num].nxt=g[u];
    g[u]=num;
    e[++num].v=u;
    e[num].f=0;
    e[num].nxt=g[v];
    g[v]=num;
}

void bfs(){
    memset(d,0,sizeof(d));
    while(!que.empty()) que.pop();
    vis[s]=1,que.push(s);
    while(!que.empty()){
        int u=que.front();que.pop();
        for(int i=g[u];i;i=e[i].nxt){
            if(e[i].f&&!vis[e[i].v]){
                d[e[i].v]=d[u]+1;
                vis[e[i].v]=1;
                que.push(e[i].v);
            }
        }
    }
}

int dfs(int u,int flow){
    if(u==t)
        return flow;
    else{
        int ans=0;
        for(int i=g[u];flow&&i;i=e[i].nxt){
            if(e[i].f&&d[e[i].v]==d[u]+1){
                int dd=dfs(e[i].v,min(e[i].f,flow));
                e[i].f-=dd;
                e[i^1].f+=dd;
                flow-=dd;
                ans+=dd;
            }
        }
        return ans;
    }
}

int dinic(){
    int ans=0;
    while(true){
        memset(vis,0,sizeof(vis));
        bfs();
        if(!vis[t])
            return ans;
        ans+=dfs(s,inf);
    }
}

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        num=1;
        cout << "Case " << cas << ": ";
        memset(g,0,sizeof(g));
        cin>>n>>m;
        int x,y,z;
        s=1,t=n;
        for(int i=1;i<=m;i++)
            cin>>x>>y>>z,addedge(x,y,z);
        cout << dinic() << endl;
    }
    return 0;
}