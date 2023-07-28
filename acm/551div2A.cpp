#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t,n,a,b,mx=(int)1e9;
    int count[(int)1e5+10];
    int ans;
    while(cin>>n>>t){
        for(int i=1;i<=n;i++) {
            cin >> a >> b;
            int k;
            for (k = a; k < t; k += b);
            if(mx>k) {
                mx=k;
                ans=i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
