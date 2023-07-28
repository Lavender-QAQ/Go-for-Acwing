#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn=1010;

struct node{
    int x,y;
    bool operator < (const node& a) const{
        return x>a.x;
    }
    node(int x,int y){
        this->x=x;
        this->y=y;
    };
};

int map[maxn][maxn];
int d[maxn];

int main(){
    int n,m;
    ios::sync_with_stdio(false);
    while(cin>>m>>n){
        for(int i=1;i<=n;i++)
            d[i]=(int)1e9;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                map[i][j]=i==j?0:(int)1e9;
        int a,b,val;
        for(int i=0;i<m;i++){
            cin>>a>>b>>val;
            map[a][b]=min(map[a][b],val);
            map[b][a]=min(map[b][a],val);
        }
        priority_queue<node> que;
        d[1]=0;
        que.push(node(d[1],1));
        while(!que.empty()){
            int u=que.top().y;que.pop();
            for(int v=1;v<=n;v++){
                if(map[u][v]!=(int)1e9&&v!=u) {
                    if (d[v] > d[u] + map[u][v]) {
                        d[v] = d[u] + map[u][v];
                        que.push(node(d[v], v));
                    }
                }
            }
        }
        cout << d[n] << endl;
    }
    return 0;
}