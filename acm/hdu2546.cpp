#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1200];

int main()
{
    int n;
    int *v;
    while(cin>>n){
        if(n==0)
            break;
        memset(dp,0,sizeof(dp));
        v=(int*)malloc(sizeof(int)*(n+50));
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v,v+n);
        int mx=v[n-1];
        int m;
        cin>>m;
        if(m<5){
            cout << m <<endl;
            continue;
        }
        m-=5;
        for(int i=0;i<n-1;i++){
            for(int j=m;j-v[i]>=0;j--){
                dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
            }
        }
        cout << m-dp[m]-mx+5 <<endl;
    }
    return 0;
}