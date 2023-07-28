#include <iostream>
#include <algorithm>
using namespace std;

const char ch[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};

string cal(int n){
    if(n==0) return "00";
    string s;
    while(n){
        s+=ch[n%13];
        n/=13;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    int x;
    string s;
    cout << '#';
    for(int i=0;i<3;i++){
        cin>>x;
        s=cal(x);
        if(s.length()==1) cout << '0';
        cout << s;
    }
    cout << endl;
    return 0;
}