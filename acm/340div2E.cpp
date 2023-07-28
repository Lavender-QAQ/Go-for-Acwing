#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=1<<20;

int n,m,k,pos[maxn],a[maxn],c[maxn];
long long ans[maxn],Ans=0;

struct node{
    int l,r,id;
}q[maxn];

bool cmp(node a,node b){
    if(pos[a.l]==pos[b.l])
        return a.r<b.r;
    else
        return pos[a.l]<pos[b.l];
}

void add(int i){
    Ans+=c[a[i]^k];
    c[a[i]]++;
}

void del(int i){
    c[a[i]]--;
    Ans-=c[a[i]^k];
}

int main(){
    ios::sync_with_stdio(false);
    memset(c,0,sizeof(c));
    cin>>n>>m>>k;
    int L=1,R=0;
    c[0]=1;
    int block=(int)sqrt(n);
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i] = a[i] ^ a[i - 1];
        pos[i] = i / block;
    }
    for(int i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+1+m,cmp);
    for(int i=1;i<=m;i++){
        while(L<q[i].l){
            del(L-1);
            L++;
        }
        while(L>q[i].l){
            L--;
            add(L-1);
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
    return 0;
}

