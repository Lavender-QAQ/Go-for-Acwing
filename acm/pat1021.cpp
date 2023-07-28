#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
const int maxn=(int)3e4+10;

int h[maxn],e[maxn],ne[maxn],idx,vis[maxn],n,f[maxn],mx;
set<int> s;
vector<int> ans;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}


void dfs(int u,int d){
    vis[u]=1;
    if(d>mx){
        ans.clear();
        ans.push_back(u);
        mx=d;
    }
    else if(d==mx) ans.push_back(u);
    for(int i=h[u];i!=-1;i=ne[i]){
        int v=e[i];
        if(!vis[v]) dfs(v,d+1);
    }
}

int main(){
    memset(h,-1,sizeof h);
    int a,b;
    cin>>n;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=0;i<n-1;i++) {
        cin>>a>>b,add(a,b),add(b,a);
        int fx=find(a),fy=find(b);
        if(fx!=fy)
            f[fx]=fy;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) s.insert(find(i));
    if(s.size()==1){
        mx=-1;
        s.clear();
        dfs(1,0);
        for(auto x:ans) s.insert(x);
        memset(vis,0,sizeof vis);
        mx=-1;
        dfs(ans[0],0);
        for(auto x:ans) s.insert(x);
        for(auto x:s) cout << x << endl;
    }
    else printf("Error: %d components",(int)s.size());
    return 0;
}