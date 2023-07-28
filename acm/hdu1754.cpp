#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

const int N=200000+10;
struct Node{
    int left,right,val;
}node[N*4];
int a[N];

int max(int x,int y){
    return x>=y?x:y;
}

void build(int v,int l,int r){
    node[v].left=l;
    node[v].right=r;
    if(l==r){
        node[v].val=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(v<<1,l,mid);
    build((v<<1)|1,mid+1,r);
    node[v].val=max(node[v<<1].val,node[(v<<1)|1].val);
}

void update(int v,int x,int y){
    int l=node[v].left;
    int r=node[v].right;
    if(l==x&&r==x){
        node[v].val=max(node[v].val,y);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)
        update(v<<1,x,y);
    else
        update((v<<1)|1,x,y);
    node[v].val=max(node[v].val,y);
}

int query(int v,int x,int y){
    int l=node[v].left;
    int r=node[v].right;
    if(l==x&&r==y)
        return node[v].val;
    int mid=(l+r)>>1;
    if(y<=mid)
        query(v<<1,x,y);
    else if(x>mid)
        query((v<<1)|1,x,y);
    else
        return max(query(v<<1,x,mid),query((v<<1)|1,mid+1,y));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        build(1,1,n);
        int a,b;
        string c;
        while(m--){
            cin>>c>>a>>b;
            if(c[0]=='U')
                update(1,a,b);
            else
                cout << query(1,a,b) << endl;
        }
    }
}