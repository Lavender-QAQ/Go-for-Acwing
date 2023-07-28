#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=(int)1e5+10;

int f[maxn],r[maxn],v[maxn];

void init(int n){
    for(int i=0;i<n;i++)
        f[i]=i,r[i]=0,v[i]=0;
}

int find(int x){
    if(x==f[x])
        return x;
    else{
        int t=f[x];
        f[x]=find(f[x]);
        v[x]+=v[t];
        return f[x];
    }
}

void merge(int x,int y,int s){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        if(r[fx]<r[fy]){
            f[fx]=fy;
            v[fx]=s-v[x]+v[y];
        }
        else{
            f[fy]=fx;
            v[fy]=v[x]-v[y]-s;
            if(r[fx]==r[fy])
                r[fx]++;
        }
    }
}

int main(){
    int n,m,q;
    while(~(scanf("%d%d%d",&n,&m,&q))){
        init(n);
        int x,y,s;
        while(m--){
            scanf("%d%d%d",&x,&y,&s);
            merge(x,y,s);
        }
        while(q--){
            scanf("%d%d",&x,&y);
            int fx=find(x);
            int fy=find(y);
            if(fx!=fy)
                printf("-1\n");
            else{
                printf("%d\n",v[x]-v[y]);
            }
        }
    }
    return 0;
}