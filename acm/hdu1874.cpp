#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn=210;

struct edge{
    int to,val;
    edge(int to,int val){
        this->to=to;
        this->val=val;
    }
};

struct node{
    int x,y;
    bool operator < (const node& a) const{
        return x<a.x;
    }
    node(int x,int y){
        this->x=x;
        this->y=y;
    };
};

vector<edge> g[maxn];
int d[maxn];

int main(){
    int n,m;
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        for(int i=0;i<n;i++)
            g[i].clear(),d[i]=(int)1e9;
        int a,b,val;
        for(int i=0;i<m;i++){
            cin>>a>>b>>val;
            g[a].emplace_back(edge(b,val));
            g[b].emplace_back(edge(a,val));
        }
        int s,t;
        cin>>s>>t;
        priority_queue<node> que;
        d[s]=0;
        que.push(node(d[s],s));
        while(!que.empty()){
            int u=que.top().y;que.pop();
            for(auto it=g[u].begin();it!=g[u].end();it++){
                int v=it->to;
                if(d[v]>d[u]+it->val){
                    d[v]=d[u]+it->val;
                    que.push(node(d[v],v));
                }
            }
        }
        if(d[t]==(int)1e9)
            cout << -1 << endl;
        else
            cout << d[t] << endl;
    }
    return 0;
}