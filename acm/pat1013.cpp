#include <iostream>
using namespace std;
const int maxn=1010*1010;

struct edge{
    int from,to;
}e[maxn];
int f[maxn];

void init(int n){
    for(int i=1;i<=n;i++)
        f[i]=i;
}

int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k,a,b,key;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        e[i]={a,b};
    }
    while(k--){
        cin>>key;
        init(n);
        for(int i=0;i<m;i++){
            if(e[i].from!=key&&e[i].to!=key){
                int fx=find(e[i].from),fy=find(e[i].to);
                if(fx!=fy){
                    f[fx]=fy;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(i!=key&&f[i]==i)
                ans++;
        cout << ans-1 << endl;
    }
    return 0;
}