#include <iostream>
#include <vector>
using namespace std;
typedef pair<string,string> P;

vector<P> ans;

int main(){
    string name,pwd;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>name>>pwd;
        bool flag=false;
        for(auto &x:pwd){
            if(x=='1') flag=true,x='@';
            if(x=='0') flag=true,x='%';
            if(x=='l') flag=true,x='L';
            if(x=='O') flag=true,x='o';
        }
        if(flag) ans.push_back({name,pwd});
    }
    if(ans.empty()){
        if(n==1) puts("There is 1 account and no account is modified");
        else printf("There are %d accounts and no account is modified\n",n);
    }
    else{
        printf("%d\n",(int)ans.size());
        for(auto x:ans){
            cout << x.first << ' ' << x.second << endl;
        }
    }
    return 0;
}