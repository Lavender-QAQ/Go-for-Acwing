#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
const int maxn=600,inf=0x3f3f3f3f;

int g[maxn][maxn],val[maxn][maxn],d[maxn],cost[maxn],vis[maxn],pre[maxn],n,m,st,ed;

void dijkstra(){
    d[st]=cost[st]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=0;j<n;j++)
            if(!vis[j]&&(t==-1||d[j]<d[t]))
                t=j;
        vis[t]=1;
        for(int j=0;j<n;j++){
            if(d[j]>d[t]+g[t][j]){
                d[j]=d[t]+g[t][j];
                cost[j]=cost[t]+val[t][j];
                pre[j]=t;
            }
            else if(d[j]==d[t]+g[t][j]&&cost[j]>cost[t]+val[t][j]){
                cost[j]=cost[t]+val[t][j];
                pre[j]=t;
            }
        }
    }
}

int main(){
    memset(g,0x3f,sizeof g);
    memset(d,0x3f,sizeof d);
    memset(val,0x3f,sizeof val);
    cin>>n>>m>>st>>ed;
    int a,b,c,x;
    while(m--){
        cin>>a>>b>>c>>x;
        g[a][b]=g[b][a]=min(g[a][b],c);
        val[a][b]=val[b][a]=min(val[a][b],x);
    }
    dijkstra();
    stack<int> ans;
    for(int i=ed;i!=st;i=pre[i])
        ans.push(i);
    cout << st;
    while(!ans.empty()){
        cout << ' ' << ans.top();
        ans.pop();
    }
    cout << ' ' << d[ed] << ' ' << cost[ed] << endl;
    return 0;
}