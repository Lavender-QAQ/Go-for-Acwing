#include <iostream>
using namespace std;
const int maxn=100010;

int a[maxn],s[maxn];

int main(){
    int n;
    long long ans=0;
    cin>>n;
    ans+=n*5;
    for(int i=1;i<=n;i++)
        cin>>a[i],s[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++){
        if(s[i]<0) ans+=4*(-s[i]);
        else if(s[i]>0) ans+=6*s[i];
    }
    cout << ans << endl;
    return 0;
}