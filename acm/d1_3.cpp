#include <iostream>
#include <cstring>
using namespace std;
const int maxn=100010;

int tree[maxn],l[maxn],r[maxn],a[maxn];

int lowbit(int x){
    return x&(-x);
}

int sum(int x){
    int res=0;
    while(x){
        res+=tree[x];
        x-=lowbit(x);
    }
    return res;
}

void add(int x,int d){
    while(x<maxn){
        tree[x]+=d;
        x+=lowbit(x);
    }
}

int main(){
    int T;
    long long ans;
    cin>>T;
    while(T--){
        ans=0;
        int n;
        cin>>n;
        int *a=new int[n+10];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        memset(tree,0,sizeof(tree));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        for(int i=1;i<=n;i++)
            l[i]=sum(a[i]),add(a[i],1);
        memset(tree,0,sizeof(tree));
        for(int i=n;i>=1;i--)
            r[i]=sum(a[i]),add(a[i],1);
        for(int i=1;i<=n;i++)
            ans+=l[i]*(n-i-r[i])+r[i]*(i-l[i]-1);
        cout << ans << endl;
    }
    return 0;
}
