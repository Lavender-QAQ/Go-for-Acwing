#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

vector<string> v;

int main(){
    int n,x;
    string s;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),[](const string& a,const string& b){
        return a+b<b+b;
    });
    deque<char> ans;
    for(auto t:v)
        for(auto x:t) ans.push_back(x);
    while(!ans.empty()&&ans.front()=='0') ans.pop_front();
    if(ans.empty()) cout << 0 << endl;
    else{
        while(!ans.empty()) cout << ans.front(),ans.pop_front();
        cout << endl;
    }
    return 0;
}