#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=(int)2e5+10;

struct node{
    int l,r,sum;
}T[maxn<<5];

int root[maxn],a[maxn],n,m,cnt;
vector<int> v;
int getid(int x){
    return (int)(lower_bound(v.begin(),v.end(),x)-v.begin()+1);
}

void update(int l,int r,int &x,int y,int k){
    T[++cnt]=T[y],T[cnt].sum++,x=cnt;
    if(l==r)
        return;
    int mid=(l+r)>>1;
    if(mid>=k)
        update(l,mid,T[x].l,T[y].l,k);
    else
        update(mid+1,r,T[x].r,T[y].r,k);
}

int query(int l,int r,int x,int y,int k){
    if(l==r)
        return l;
    int sum=T[T[y].l].sum-T[T[x].l].sum;
    int mid=(l+r)>>1;
    if(sum>=k)
        return query(l,mid,T[x].l,T[y].l,k);
    else
        return query(mid+1,r,T[x].r,T[y].r,k-sum);
}

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        cnt=0;
        v.clear();
        memset(a,0,sizeof(a));
        memset(T,0,sizeof(T));
        memset(root,0,sizeof(root));
        for(int i=1;i<=n;i++)
            cin>>a[i],v.push_back(a[i]);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int i=1;i<=n;i++)
            update(1,n,root[i],root[i-1],getid(a[i]));
        int l,r,k;
        while(m--){
            cin>>l>>r>>k;
            cout << v[query(1,n,root[l-1],root[r],k)-1] << endl;
        }
    }
    return 0;
}