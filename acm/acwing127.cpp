#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int maxn=100010;
typedef long long ll;
typedef pair<ll,ll> P;

int n,m;
P a[maxn],b[maxn];
//a机器 b任务

bool cmp(const P& a,const P& b){
    if(a.first==b.first)
        return a.second>b.second;
    else
        return a.first>b.first;
}

int main(){
    while(cin>>n>>m){
        for(int i=0;i<n;i++)
            cin>>a[i].first>>a[i].second;
        for(int i=0;i<m;i++)
            cin>>b[i].first>>b[i].second;
        sort(a,a+n,cmp);
        sort(b,b+m,cmp);
        multiset<int> s;
        ll ans=0,cnt=0;
        for(int i=0,j=0;i<m;i++){
            while(j<n&&b[i].first<=a[j].first) s.insert(a[j++].second);
            auto it=s.lower_bound(b[i].second);
            if(it!=s.end()){
                ans+=b[i].first*500+2*b[i].second;
                cnt++;
                s.erase(it);
            }
        }
        cout << cnt << ' ' << ans << endl;
    }
    return 0;
}

