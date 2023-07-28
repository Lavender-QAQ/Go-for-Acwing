#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=5050;

int mp[maxn][maxn],n,r;

int main(){
    int x,y,w;
    while(~scanf("%d%d",&n,&r)){
        int mx=r,my=r;
        memset(mp,0,sizeof(mp));
        for(int i=0;i<n;i++)
            cin>>x>>y>>w,x++,y++,mx=max(mx,x),my=max(my,y),mp[x][y]=w;
        for(int i=1;i<=mx;i++)
            for(int j=1;j<=my;j++)
                mp[i][j]+=mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
        int ans=0;
        for(int i=r;i<=mx;i++)
            for(int j=r;j<=my;j++)
                ans=max(ans,mp[i][j]-mp[i-r][j]-mp[i][j-r]+mp[i-r][j-r]);
        printf("%d\n",ans);
    }
    return 0;
}