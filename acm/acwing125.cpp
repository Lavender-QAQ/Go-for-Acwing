#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=50010;

typedef pair<ll,ll> P;
P p[maxn];
int n;

bool cmp(const P& a,const P& b){
    return a.first+a.second < b.first+b.second;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;
    sort(p,p+n,cmp);
    ll sum=0;
    ll ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,sum-p[i].second);
        sum+=p[i].first;
    }
    cout << ans<< endl;
    return 0;
}

