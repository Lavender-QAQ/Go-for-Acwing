#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = (int)1e5+10;

struct Node{
    int l,r,sum;
}T[maxn<<5];

int root[maxn],a[maxn],n,m,cnt;

vector<int> v;
int getid(int x){
    return (int)(lower_bound(v.begin(),v.end(),x)-v.begin()+1);
}

void update(int l,int r,int& x,int y,int k){
    T[++cnt]=T[y],T[cnt].sum++,x=cnt;
}

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        cnt=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],v.push_back(a[i]);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
    }
    return 0;
}