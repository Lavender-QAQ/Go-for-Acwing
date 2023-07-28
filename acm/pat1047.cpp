#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v[5000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k,x;
    string s;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>s>>m;
        while(m--){
            cin>>x;
            v[x].push_back(s);
        }
    }
    for(int i=1;i<=k;i++){
        sort(v[i].begin(),v[i].end());
        cout << i << ' ' << v[i].size() << endl;
        for(auto j:v[i]) cout << j << endl;
    }
    return 0;
}