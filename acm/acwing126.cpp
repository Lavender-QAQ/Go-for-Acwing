#include <iostream>
#include <climits>
using namespace std;
const int maxn=110;

int sum[maxn][maxn];

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>sum[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sum[i][j]+=sum[i-1][j];
    int ans=INT_MIN;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int last=0;
            for(int k=1;k<=n;k++){
                last=max(last,0)+sum[j][k]-sum[i-1][k];
                ans=max(ans,last);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
