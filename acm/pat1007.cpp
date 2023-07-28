#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=100010;

struct info{
    int sum,l,r;
};
int a[maxn],s[maxn];
vector<info> v;

int main(){
    int n,flag=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i],s[i]=s[i-1]+a[i];
        if(a[i]>=0)
            flag=1;
    }
    if(!flag){
        cout << 0 << ' ' << a[1] << ' ' << a[n] << endl;
        return 0;
    }
    int m=a[0],id=0,ans=-(1<<30),l=0,r=0;
    for(int i=1;i<=n;i++){
        if(ans<s[i]-m){
            ans=s[i]-m;
            l=id;
            r=i;
        }
        if(m>s[i]){
            m=s[i];
            id=i;
        }
    }
    cout << ans << ' ' << a[l+1] << ' ' << a[r] << endl;
    return 0;
}