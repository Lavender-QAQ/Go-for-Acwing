#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

const int maxn=1010;

queue<int> w[maxn];
unordered_map<int,int> mp;
int tt[maxn];

int main(){
    int n,m,k,q,x;
    cin>>n>>m>>k>>q;
    for(int i=1;i<=k;i++){
        cin>>x;
        int t=1;
        for(int j=1;j<=n;j++){
            if(i<=n*m){
                if(w[j].size()<w[t].size()) t=j;
            }
            else{
                if(w[j].front()<w[t].front()) t=j;
            }
        }
        if(i>n*m) w[t].pop();
        tt[t]+=x;
        w[t].push(tt[t]);
        if(tt[t]-x<540) mp.insert({i,tt[t]});
    }
    while(q--){
        cin>>x;
        if(!mp.count(x)) puts("Sorry");
        else printf("%02d:%02d\n",8+mp[x]/60,mp[x]%60);
    }
    return 0;
}