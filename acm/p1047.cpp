#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=(int)1e5;

int a[maxn],n,m;

struct node{
    int l,r,sum,lazy;
    void update(int val){
        if(sum>=(r-l+1)*val)
            sum-=(r-l+1)*val;
        else
            sum=0;
        lazy=val;
    }
}tree[maxn<<2];

void push_up(int x){
    tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
}

void push_down(int x){
    int val=tree[x].lazy;
    if(val){
        tree[x<<1].update(val);
        tree[x<<1|1].update(val);
        tree[x].lazy=0;
    }
}

void build(int x,int l,int r){
    tree[x].l=l,tree[x].r=r,tree[x].lazy=0;
    if(l==r)
        tree[x].sum=a[l];
    else{
        int mid=(l+r)/2;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
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
        if(r>mid) update(x<<1|1,l,r,val);
        push_up(x);
    }
}

int query(int x,int l,int r){
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)
        return tree[x].sum;
    else{
        int ans=0;
        push_down(x);
        int mid=(L+R)/2;
        if(l<=mid) ans+=query(x<<1,l,r);
        if(r>mid) ans+=query(x<<1|1,l,r);
        push_up(x);
        return ans;
    }
}

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        n++;
        fill(a+1,a+n+1,1);
        build(1,1,n);
        int left,right;
        while(m--){
            cin>>left>>right;
            left++,right++;
            update(1,left,right,1);
        }
        cout << query(1,1,n) << endl;
    }
    return 0;
}
