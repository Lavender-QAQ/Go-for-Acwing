#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 2000;
int mp[maxn][maxn];
int f[1000*1000+10];
struct edge
{
    int from,to,w;
    edge(int from,int to,int w){
        this->from=from;
        this->to=to;
        this->w=w;
    }
};
vector<edge> e;
void add(int i,int j,int w){
    e.emplace_back(edge(i,j,w));
}
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int kruscal(int n){
    int ans=0,num=0;
    for(int i=0;i<n;i++)
        f[i]=i;
    for(int i=0;i<e.size();i++)
    {
        edge temp=e[i];
        int u=temp.from;int v=temp.to;
        int x=find(u);
        int y=find(v);
        if(x!=y)
        {
            f[x]=y;
            ans+=e[i].w;
            num++;
            if(num==n-1)break;
        }
    }
    return ans;
}
int main() {
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        int n, m;
        e.clear();
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &mp[i][j]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j != m - 1)
                    add(i * m + j, i * m + j + 1, abs(mp[i][j] - mp[i][j + 1]));
                if (i != n - 1)
                    add(i * m + j, (i + 1) * m + j, abs(mp[i][j] - mp[i + 1][j]));
            }
        }
        sort(e.begin(), e.end(), cmp);
        int ans=kruscal(n*m);
        printf("Case #%d:\n%d\n",cas,ans);
    }
}
