#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int,int> mp;

int main(){
    int n,m,x;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;i++){
        scanf("%d",&x);
        mp[x]++;
    }
    for(auto i:mp){
        if(i.second>n*m/2){
            printf("%d\n",i.first);
            break;
        }
    }
    return 0;
}