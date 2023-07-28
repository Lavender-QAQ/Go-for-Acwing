#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=3000;
typedef pair<int,int> P;

int c,l;
P spf[maxn];
map<int,int> mp;

int main(){
    ios::sync_with_stdio(false);
    while(cin>>c>>l){
        mp.clear();
        for(int i=0;i<c;i++)
            cin>>spf[i].first>>spf[i].second;
        int a,b;
        for(int i=0;i<l;i++){
            cin>>a>>b;
            mp[a]+=b;
        }
        sort(spf,spf+c);
        mp[0]=mp[1001]=0;
        int ans=0;
        for(int i=c-1;i>=0;i--){
            auto it=mp.upper_bound(spf[i].second);
            it--;
            if(it->first>=spf[i].first&&it->first<=spf[i].second){
                it->second--;
                ans++;
                if(it->second==0)
                    mp.erase(it);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

