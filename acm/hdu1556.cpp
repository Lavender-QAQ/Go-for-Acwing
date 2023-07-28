#include <iostream>
using namespace std;
const int maxn=100010;

struct node{
    int l,r,sum,lazy;
    void update(int x){
        sum+=x;
        lazy+=x;
    }
}tree[maxn*4];

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
        tree[x].sum=0;
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
        return ans;
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n,a,b;
    while(cin>>n&&n) {
        build(1,1,n);
        for(int i=1;i<=n;i++) {
            cin >> a >> b;
            update(1, a, b, 1);
        }
        for(int i=1;i<=n;i++){
            if(i>1)
                cout << ' ';
            cout << query(1,i,i);
        }
        cout << endl;
    }
    return 0;
}
