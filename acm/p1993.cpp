#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=100010,maxm=4e5+10;

int h[maxn],e[maxm],ne[maxm],w[maxm],d[maxn],cnt[maxn],vis[maxn],idx,n,m;

void add(int a,int b,int c){
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}

bool spfa(){
    queue<int> que;
    for(int i=1;i<=n;i++)
        vis[i]=1,que.push(i);
    while(!que.empty()){
        int u=que.front();que.pop();
        vis[u]=0;
        if(cnt[u]>=n) return true;
        for(int i=h[u];i!=-1;i=ne[i]){
            int v=e[i],val=w[i];
            if(d[v]>d[u]+val){
                d[v]=d[u]+val;
                cnt[v]=cnt[u]+1;
                if(!vis[v]){
                    vis[v]=1;
                    que.push(v);
                }
            }
        }
    }
    return false;
}

int main(){
    int a,b,c,op;
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,-c);
        }
        else if(op==2){
            scanf("%d%d%d",&a,&b,&c);
            add(b,a,c);
        }
        else{
            scanf("%d%d",&a,&b);
            add(a,b,0),add(b,a,0);
        }
    }
    spfa()?puts("No"):puts("Yes");
    return 0;
}
