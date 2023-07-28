#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e6+10;

int a[maxn],b[maxn];

int main(){
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    int ans=0;
    for(int i=0,j=0;i<n&&j<m;i++,j++)
        if(a[i]<0&&b[j]<0) ans+=a[i]*b[j];
    for(int i=n-1,j=m-1;i>=0&&j>=0;i--,j--)
        if(a[i]>0&&b[j]>0) ans+=a[i]*b[j];
    cout << ans << endl;
    return 0;
}