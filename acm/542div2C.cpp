#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn=60;
typedef pair<int,int> P;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
char map[maxn][maxn],n,vis[maxn][maxn];

int dist(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void BFS(int x,int y,vector<P>& v){
    queue<P> que;
    vis[x][y]=1;
    que.push(make_pair(x,y));
    v.emplace_back(make_pair(x,y));
    while(!que.empty()){
        P p=que.front();que.pop();
        for(int i=0;i<4;i++){
            int nx=p.first+dx[i],ny=p.second+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=n)
                continue;
            if(!vis[nx][ny]&&map[nx][ny]=='0'){
                vis[nx][ny]=1;
                que.push(make_pair(nx,ny));
                v.emplace_back(make_pair(nx,ny));
            }
        }
    }
}

int main(){
    int s1,s2,t1,t2;
    while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof(vis));
        cin>>s1>>t1>>s2>>t2;
        s1--,s2--,t1--,t2--;
        getchar();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>map[i][j];
        vector<P> s,t;
        BFS(s1,t1,s);
        memset(vis,0,sizeof(vis));
        BFS(s2,t2,t);
        s.emplace_back(make_pair(s1,t1));
        t.emplace_back(make_pair(s2,t2));
        int mi=(int)1e9;
        for(auto it=s.begin();it!=s.end();it++){
            for(auto jt=t.begin();jt!=t.end();jt++){
                if(dist(it->first,it->second,jt->first,jt->second)<mi)
                    mi=dist(it->first,it->second,jt->first,jt->second);
            }
        }
        printf("%d\n",mi);
    }
    return 0;
}