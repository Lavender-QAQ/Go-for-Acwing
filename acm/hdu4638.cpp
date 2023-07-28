#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn=(int)1e6;

struct node{
    int l,r,id;
}q[maxn];

int n,m,pos[maxn],vis[maxn],a[maxn];
int L=1,R=0,ans[maxn],Ans;

bool cmp(node a,node b){
    if(pos[a.l]==pos[b.r])
        return a.r<b.r;
    else
        return pos[a.l]<pos[b.l];
}

void add(int x){
    vis[a[x]]=1;
    if(!vis[a[x]-1]&&!vis[a[x]+1])
        Ans++;
    else if(vis[a[x]-1]&&vis[a[x]+1])
        Ans--;
}

void del(int x){
    vis[a[x]]=0;
    if(!vis[a[x]-1]&&!vis[a[x]+1])
        Ans--;
    else if(vis[a[x]-1]&&vis[a[x]+1])
        Ans++;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        Ans=0;
        L=1,R=0;
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        memset(q,0,sizeof(q));
        scanf("%d%d",&n,&m);
        int block=(int)sqrt(n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i,pos[i]=i/block;
        sort(q+1,q+1+m,cmp);
        for(int i=1;i<=m;i++){
            while(L<q[i].l){
                del(L);
                L++;
            }
            while(L>q[i].l){
                L--;
                add(L);
            }
            while(R<q[i].r){
                R++;
                add(R);
            }
            while(R>q[i].r){
                del(R);
                R--;
            }
            ans[q[i].id]=Ans;
        }
        for(int i=1;i<=m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}

