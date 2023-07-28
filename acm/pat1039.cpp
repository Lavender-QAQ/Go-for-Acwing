#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

unordered_map<string,vector<int>> mp;

int main(){
    int n,m,a,b;
    cin>>n>>m;
    string s;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        while(b--){
            cin>>s;
            mp[s].push_back(a);
        }
    }
    for(int i=0;i<n;i++){
        cin>>s;
        auto v=mp[s];
        sort(v.begin(),v.end());
        cout << s << ' ' << v.size();
        for(auto x:v) cout << ' ' << x;
        cout << endl;
    }
    return 0;
}