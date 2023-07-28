#include <iostream>
#include <stack>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int ans=a+b;
    if(ans==0){
        cout << 0 << endl;
        return 0;
    }
    if(ans<0) {
        cout << '-';
        ans=-ans;
    }
    stack<char> s;
    int cnt=0;
    while(ans){
        if(cnt==3) {
            s.push(',');
            cnt=0;
        }
        s.push((char)('0'+ans%10));
        ans/=10;
        cnt++;
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
        cnt++;
    }
    cout << endl;
    return 0;
}