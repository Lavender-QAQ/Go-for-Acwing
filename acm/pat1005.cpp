#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

unordered_map<int,string> mp;
stack<int> sta;

int main(){
    mp.insert({0,"zero"});
    mp.insert({1,"one"});
    mp.insert({2,"two"});
    mp.insert({3,"three"});
    mp.insert({4,"four"});
    mp.insert({5,"five"});
    mp.insert({6,"six"});
    mp.insert({7,"seven"});
    mp.insert({8,"eight"});
    mp.insert({9,"nine"});
    string s;
    long long ans;
    cin>>s;
    for(auto c:s){
        ans+=c-'0';
    }
    if(ans==0){
        cout << mp[0] << endl;
        return 0;
    }
    while(ans){
        sta.push(ans%10);
        ans/=10;
    }
    int cnt=0;
    while(!sta.empty()){
        if(cnt) printf(" ");
        cout << mp[sta.top()];
        sta.pop();
        cnt++;
    }
    cout << endl;
    return 0;
}