#include <iostream>
#include <cstring>
using namespace std;
const int maxn=100010;


struct node{
    int l,r;
    int sum,lazy;
    void update(int val){
        sum=val;
        lazy=val;
    }
}tree[4*maxn];

struct Q{
    int l,r;
}q[maxn];

void push_up(int x){
    tree[x].sum=max(tree[x<<1].sum,tree[(x<<1)|1].sum);
}

void push_down(int x){
    int val=tree[x].lazy;
    if(val){
        tree[x<<1].update(val);
        tree[(x<<1)|1].update(val);
        tree[x].lazy=0;
    }
}

void build(int x,int l,int r){
    tree[x].l=l,tree[x].r=r,tree[x].lazy=0;
    if(l==r)
        tree[x].sum=0;
    else{
        int mid=(l+r)/2;
        build(x<<1,l,mid);
        build((x<<1)|1,mid+1,r);
        push_up(x);
    }
}

void update(int x,int l,int r,int val){
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)
        tree[x].update(val);
    else{
        push_down(x);
        int mid=(L+R)/2;
        if(l<=mid) update(x<<1,l,r,val);
        if(r>mid) update((x<<1)|1,l,r,val);
        push_up(x);
    }
}

int query(int x,int l,int r){
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)
        return tree[x].sum;
    else{
        int sum=0;
        push_down(x);
        int mid=(L+R)/2;
        if(l<=mid) sum=max(sum,query(x<<1,l,r));
        if(r>mid) sum=max(sum,query((x<<1)|1,l,r));
        push_up(x);
        return sum;
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        memset(q,0,sizeof(q));
        memset(tree,0,sizeof(tree));
        int mx=0;
        for(int i=1;i<=n;i++){
            cin>>q[i].l>>q[i].r;
            mx=max(mx,q[i].r);
        }
        build(1,1,mx);
        for(int i=1;i<=n;i++) {
            int ans=query(1, q[i].l, q[i].r)+1;
            cout << ans << endl;
            update(1, q[i].l, q[i].r, ans);
        }
    }
    return 0;
}