#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=50010;
const int maxm=200010;
const int N=1e6+10;
typedef long long ll;

struct node{
    int l,r,id;
}q[maxm];

int pos[maxm],num[N],a[maxn];
ll ans[maxm],Ans;
int n,m;
bool cmp(node a,node b){
    if(pos[a.l]==pos[b.l])
        return a.r<b.r;
    else
        return pos[a.l]<pos[b.l];
}

int L=1,R=0;

void add(int x){
    if(num[a[x]]==0)
        Ans+=a[x];
    num[a[x]]++;
}

void del(int x){
    if(num[a[x]]==1)
        Ans-=a[x];
    num[a[x]]--;
}

int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        L=1,R=0;
        memset(num,0,sizeof(num));
        Ans=0;
        scanf("%d",&n);
        int block=(int)sqrt(n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
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
            printf("%lld\n",ans[i]);
    }
    return 0;
}

