#include <iostream>
#include <cstring>
using namespace std;
const int maxn=100005;

int f[maxn],r[maxn],vis[maxn];

void init(){
    for(int i=1;i<maxn;i++)
        f[i]=i;
    memset(r,0,sizeof(r));
    memset(vis,0,sizeof(vis));
}

int find(int x){
    return f[x]=f[x]==x?x:find(f[x]);
}

void merge(int a,int b){
    int x=find(a);
    int y=find(b);
    if(r[x]<r[y])
        f[x]=y;
    else{
        f[y]=x;
        if(r[x]==r[y])
            r[x]++;
    }
}

bool same(int a,int b){
    return find(a)==find(b);
}

bool judge(){
    int k;
    for(int i=1;i<maxn;i++)
        if(vis[i]) {
            k = i;
            break;
        }
    for(int i=k+1;i<maxn;i++)
        if(vis[i]&&!same(i,k))
            return false;
    return true;
}

int main(){
    int a,b;
    int flag=1;
    init();
    while(cin>>a>>b){
        vis[a]=vis[b]=1;
        if(a==-1&&b==-1)
            break;
        if(a==0&&b==0) {
            if(!judge())
                cout << "No" << endl;
            else if(flag)
                cout << "Yes" << endl;
            flag=1;
            init();
            continue;
        }
        if(flag&&same(a,b)) {
            cout << "No" << endl;
            flag=0;
        }
        else
            merge(a,b);
    }
    return 0;
}

