#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=(int)1e6+10;

struct node{
    int l,r,sum;
}T[maxn*9];

int a[maxn],root[maxn],n,m,cnt,pre[maxn],nex[maxn];

void update(int l,int r,int &x,int y,int k){
    T[++cnt]=T[y],T[cnt].sum++,x=cnt;
    if(l==r)
        return;
    int mid=(l+r)>>1;
    if(mid>=k) update(l,mid,T[x].l,T[y].l,k);
    else update(mid+1,r,T[x].r,T[y].r,k);
}

int query(int l,int r,int x,int y,int k){
    int ans=0;
    if(l==r)
        return T[y].sum-T[x].sum;
    int mid=(l+r)>>1;
    if(mid>=k)
        ans+=(T[T[y].r].sum-T[T[x].r].sum+query(l,mid,T[x].l,T[y].l,k));
    else
        ans+=query(mid+1,r,T[x].r,T[y].r,k);
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
        cnt=0;
        memset(root,0,sizeof(root));
        memset(T,0,sizeof(T));
        memset(a,0,sizeof(a));
        memset(pre,0,sizeof(pre));
        fill(nex+1,nex+1+n,n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(pre[a[i]])
                nex[pre[a[i]]]=i;
            pre[a[i]]=i;
        }
        /*for(int i=1;i<=n;i++)
            cout << nex[i] << " ";
        cout << endl;*/
        cin>>m;
        for(int i=1;i<=n;i++)
            update(1,n+1,root[i],root[i-1],nex[i]);
        int l,r;
        while(m--){
            cin>>l>>r;
            cout << query(1,n+1,root[l-1],root[r],r+1) << endl;
        }
    }
    return 0;
}