#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=50010;
typedef long long ll;

int a[maxn],c[maxn],pos[maxn],n,m,k;
ll ans[maxn],Ans;

struct node{
    int l,r,id;
}q[maxn];

bool cmp(node a,node b){
    if(pos[a.l]==pos[b.l])
        return a.r<b.r;
    else
        return pos[a.l]<pos[b.l];
}

int L,R;

void add(int x){
    Ans-=c[a[x]]*c[a[x]];
    c[a[x]]++;
    Ans+=c[a[x]]*c[a[x]];
}

void del(int x){
    Ans-=c[a[x]]*c[a[x]];
    c[a[x]]--;
    Ans+=c[a[x]]*c[a[x]];
}


int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m>>k){
        L=1,R=0,Ans=0;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        int block=(int)sqrt(n);
        for(int i=1;i<=n;i++)
            cin>>a[i],pos[i]=i/block;
        for(int i=1;i<=m;i++)
            cin>>q[i].l>>q[i].r,q[i].id=i;
        sort(q+1,q+m+1,cmp);
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
            cout << ans[i] << endl;
    }
    return 0;
}