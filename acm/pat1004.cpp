#include <iostream>
#include <cstring>
#include <map>
using namespace std;
const int maxn=1e5+10;

map<int,int> ans;
int e[maxn],ne[maxn],h[maxn],d[maxn],idx,n,m,mx;

void init(){
    memset(h,-1,sizeof h);
    memset(d,0,sizeof d);
    idx=0;
}

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int n){
    if(h[u]==-1){
        ans[n]++;
        mx=max(mx,n);
    }
    else{
        for(int i=h[u];i!=-1;i=ne[i]){
            int v=e[i];
            dfs(v,n+1);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    if(n==0) return 0;
    init();
    int a,k,b;
    while(m--){
        scanf("%d%d",&a,&k);
        while(k--){
            scanf("%d",&b);
            add(a,b);
            d[b]++;
        }
    }
    int root=-1;
    for(int i=1;i<=n;i++)
        if(d[i]==0){
            root=i;
            break;
        }
    dfs(root,0);
    for(int i=0;i<=mx;i++){
        if(i) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
    return 0;
}