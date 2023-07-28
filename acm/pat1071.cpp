#include <iostream>
#include <sstream>
#include <map>
using namespace std;

map<string,int> mp;

int main(){
    string str,s;
    int flag=0;
    getline(cin,str);
    for(auto &c:str){
        if(c>='A'&&c<='Z') c=c-'A'+'a';
        if(!((c>='a'&&c<='z')||(c>='0'&&c<='9')))
            c=' ';
    }
    stringstream ss;
    ss<<str;
    while(ss>>s){
        mp[s]++;
    }
    int cnt=0;
    string ans;
    for(auto x:mp){
        if(cnt<x.second) ans=x.first,cnt=x.second;
    }
    cout << ans << ' ' << cnt << endl;
    return 0;
}