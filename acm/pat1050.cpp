#include <iostream>
using namespace std;

int vis[10010];

int main(){
    string s,p;
    getline(cin,s);
    getline(cin,p);
    for(auto x:p) vis[x]=1;
    for(auto x:s){
        if(!vis[x]) cout << x;
    }
    cout << endl;
    return 0;
}