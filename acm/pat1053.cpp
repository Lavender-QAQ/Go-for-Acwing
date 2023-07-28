#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=200;

int a[maxn];
vector<int> v[maxn];

void dfs(int u,int val,vector<int>& path){
    path.push_back(u);
    val-=a[u];
    if(val<0){
        path.pop_back();
        return;
    }
    if(val==0){
        if(v[u].empty()){
            for(int i=0;i<(int)path.size();i++){
                if(i) printf(" ");
                printf("%d",a[path[i]]);
            }
            puts("");
        }
        path.pop_back();
        return;
    }
    sort(v[u].begin(),v[u].end(),[](const int& p,const int& q){
        return a[p]>a[q];
    });
    for(auto x:v[u])
        dfs(x,val,path);
    path.pop_back();
}

int main(){
    int n,m,k,id,x,y;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    while(m--){
        scanf("%d%d",&id,&x);
        while(x--){
            scanf("%d",&y);
            v[id].push_back(y);
        }
    }
    vector<int> path;
    dfs(0,k,path);
    return 0;
}