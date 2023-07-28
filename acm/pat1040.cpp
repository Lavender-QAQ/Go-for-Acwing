#include <iostream>
using namespace std;

string s;

bool judge(int l,int r){
    for(int i=l;i<=r;i++){
        if(s[i]!=s[r-(i-l)])
            return false;
    }
    return true;
}

int main(){
    getline(cin,s);
    int ans=1;
    for(int i=0;i<s.length()-1;i++)
        for(int j=i+1;j<s.length();j++)
            if(judge(i,j))
                ans=max(ans,j-i+1);
    cout << ans << endl;
    return 0;
}