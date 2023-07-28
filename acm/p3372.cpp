#include <iostream>
using namespace std;
const int maxn=100010;

int a[maxn];

struct node{
    int l,r;
    long long sum,lazy;
    void update(long long val){
        sum+=val*(r-l+1);
        lazy+=val;
    }
}tree[4*maxn];

void push_up(int x){
    tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
}

void push_down(int x){
    long long val=tree[x].lazy;
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

void update(int x,int l,int r,long long val){
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

long long query(int x,int l,int r){
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)
        return tree[x].sum;
    else{
        long long sum=0;
        push_down(x);
        int mid=(L+R)/2;
        if(l<=mid) sum+=query(x<<1,l,r);
        if(r>mid) sum+=query(x<<1|1,l,r);
        push_up(x);
        return sum;
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        build(1,1,n);
        int op,left,right,val;
        while(m--){
            cin>>op;
            if(op==1){
                cin>>left>>right>>val;
                update(1,left,right,val);
            }
            else if(op==2){
                cin>>left>>right;
                cout << query(1,left,right) << endl;
            }
        }
    }
    return 0;
}
