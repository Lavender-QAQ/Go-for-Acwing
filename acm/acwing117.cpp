#include <iostream>
#include <vector>
using namespace std;

vector<int> v[14];
int s[13];

int get(char c){
    if(c=='A') return 1;
    else if(c>='2'&&c<='9') return c-'0';
    else if(c=='0') return 10;
    else if(c=='J') return 11;
    else if(c=='Q') return 12;
    else if(c=='K') return 13;
}

int main(){
    char c[2];
    for(int i=1;i<=13;i++){
        for(int j=0;j<4;j++){
            cin>>c;
            v[i].push_back(get(*c));
        }
    }
    for(int i=0;i<4;i++){
        int t=v[13][i];
        while(t!=13){
            s[t]++;
            int p=v[t].back();
            v[t].pop_back();
            t=p;
        }
    }
    int ans=0;
    for(int i=1;i<=12;i++)
        if(s[i]==4)
            ans++;
    cout << ans << endl;
    return 0;
}
