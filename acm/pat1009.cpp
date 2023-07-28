#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
typedef pair<int,double> P;

unordered_map<int,double> mp;
vector<P> a,b;

int main(){
    int k,n,mx=0;
    double m;
    cin>>k;
    while(k--){
        cin>>n>>m;
        a.push_back({n,m});
    }
    cin>>k;
    while(k--){
        cin>>n>>m;
        b.push_back({n,m});
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            mx=max(mx,a[i].first+b[j].first);
            mp[a[i].first+b[j].first]+=a[i].second*b[j].second;
        }
    }
    int cnt=0;
    for(int i=mx;i>=0;i--){
        if(abs(mp[i])>1e-8){
            cnt++;
        }
    }
    cout << cnt;
    for(int i=mx;i>=0;i--){
        if(abs(mp[i])>1e-8){
            printf(" %d %.1lf",i,mp[i]);
        }
    }
    puts("");
    return 0;
}