#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int t[10000];

void run(){
    memset(t,0,sizeof(t));
    for(int i=1000;i<=9999;i++){
        if((int)sqrt(i)*(int)sqrt(i)==i)
            t[i]=1;
    }
}

int main(){
    run();
    int T;
    while(cin>>T){
        int n,ans;
        while(T--){
            ans=0;
            cin>>n;
            int a=n/1000,b=n/100%10,c=n/10%10,d=n%10;
            for(int i=1;i<=9;i++){
                if()
            }
            cout << ans << endl;
        }
    }
    return 0;
}