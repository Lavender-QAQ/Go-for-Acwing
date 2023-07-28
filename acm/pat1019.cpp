#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    if(n==0){
        puts("Yes");
        puts("0");
        return 0;
    }
    queue<int> que;
    stack<int> sta;
    stack<int> ans;
    while(n){
        que.push(n%k);
        sta.push(n%k);
        ans.push(n%k);
        n/=k;
    }
    bool flag=true;
    while(!que.empty()){
        if(que.front()!=sta.top())
            flag=false;
        que.pop();
        sta.pop();
    }
    if(flag) puts("Yes");
    else puts("No");
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
        if(!ans.empty()) cout << ' ';
    }
    cout << endl;
    return 0;
}