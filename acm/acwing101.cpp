#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef pair<int,int> P;
vector<P> v;
int a[10010];

void down(int l,int r){
    a[l]--;
    a[r+1]++;
}

int main(){
    int n,p,h,m;
    while(~scanf("%d%d%d%d",&n,&p,&h,&m)){
        int x,y;
        memset(a,0,sizeof(a));
        v.clear();
        for(int i=1;i<=n;i++)
            a[i]=h;
        for(int i=n;i>=1;i--)
            a[i]-=a[i-1];
        while(m--){
            scanf("%d%d",&x,&y);
            v.emplace_back(make_pair(min(x,y),max(x,y)));
        }
        v.erase(unique(v.begin(),v.end()),v.end());
        for(auto p:v){
            if(p.second-p.first>1)
                down(p.first+1,p.second-1);
        }
        printf("%d\n",a[1]);
        for(int i=2;i<=n;i++)
            a[i]+=a[i-1],printf("%d\n",a[i]);
    }
    return 0;
}
