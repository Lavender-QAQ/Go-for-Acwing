#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int n,m,k,x;
    cin>>m>>n>>k;
    stack<int> s;
    queue<int> q;
    while(k--){
        while(!s.empty()) s.pop();
        while(!q.empty()) q.pop();
        bool flag=true;
        for(int i=0;i<n;i++) cin>>x,q.push(x);
        for(int i=1;i<=n;i++){
            s.push(i);
            while(!s.empty()&&!q.empty()&&s.top()==q.front())
                s.pop(),q.pop();
            if(s.size()==m){
                flag=false;
                break;
            }
        }
        if(!flag||!s.empty()||!q.empty()) puts("NO");
        else puts("YES");
    }
    return 0;
}