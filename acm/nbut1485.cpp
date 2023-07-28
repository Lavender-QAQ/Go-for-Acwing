#include <iostream>
using namespace std;

int main(){
    string s;int sum=0;
    while(cin>>s){
        for(int i=0;i<s.length();i++)
            sum+=s[i]-'0';
        cout << sum << endl;
        sum=0;
    }
    return 0;
}