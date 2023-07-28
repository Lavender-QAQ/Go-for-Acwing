#include <iostream>
#include <vector>
using namespace std;
const int maxn=1e5+10;

int s[maxn],dp[maxn],n,m,k;

int main(){
    int x;
    scanf("%d",&k);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        s[x]=i;
    }
    vector<int> v;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        if(s[x]) v.push_back(s[x]);
    }
    int mx=-1;
    for(int i=0;i<v.size();i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(v[i]>=v[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
        mx=max(mx,dp[i]);
    }
    printf("%d\n",mx);
    return 0;
}