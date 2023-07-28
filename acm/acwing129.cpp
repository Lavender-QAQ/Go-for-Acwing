#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> s,t;
vector<int> e;
int n,cnt;

void dfs(){
    if(cnt==20)
        return;
    if(e.size()==n){
        for(auto x:e)
            cout << x;
        cout << endl;
        cnt++;
        return;
    }
    if(!t.empty()){
        e.push_back(t.top());t.pop();
        dfs();
        t.push(e.back());e.pop_back();
    }
    if(!s.empty()){
        t.push(s.top());s.pop();
        dfs();
        s.push(t.top());t.pop();
    }
}

int main(){
    cin>>n;
    for(int i=n;i>=1;i--){
        s.push(i);
    }
    cnt=0;
    dfs();
    return 0;
}