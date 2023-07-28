#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=210;
const int inf=1<<30;

struct edge{
    int v,f,nxt;
}e[maxn<<1];
int num,n,m,s,t,g[maxn],vis[maxn],d[maxn];
queue<int> que;

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

int dfs(int u,int flow){
    if(u==t)
        return flow;
    else{
        int ans=0;
        for(int i=g[u];i&&flow;i=e[i].nxt){
            if(e[i].f&&d[e[i].v]==d[u]+1) {
                int dd = dfs(e[i].v, min(flow, e[i].f));
                e[i].f -= dd;
                e[i ^ 1].f += dd;
                flow -= dd;
                ans += dd;
            }
        }
        return ans;
    }
}

void bfs(){
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    while(!que.empty()) que.pop();
    vis[s]=1,que.push(s);
    while(!que.empty()){
        int u=que.front();que.pop();
        for(int i=g[u];i;i=e[i].nxt){
            if(!vis[e[i].v]&&e[i].f){
                d[e[i].v]=d[u]+1;
                vis[e[i].v]=1;
                que.push(e[i].v);
            }
        }
    }
}

int dinic(){
    int ans=0;
    while(true){
        bfs();
        if(!vis[t])
            return ans;
        ans+=dfs(s,inf);
    }
}

int main(){
    ios::sync_with_stdio(false);
    int x,y,z;
    while(cin>>m>>n){
        num=1;
        memset(g,0,sizeof(g));
        while(m--){
            cin>>x>>y>>z;
            addedge(x,y,z);
        }
        s=1,t=n;
        cout << dinic() << endl;
    }
    return 0;
}