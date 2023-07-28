#include <iostream>
#include <vector>
using namespace std;
const int maxn=(int)2e5+10;
typedef pair<int,int> P;

int a[maxn],s[maxn],n,m;

int search(int x,int l,int r){
    while(l<r){
        int mid=l+r>>1;
        if(s[mid]-x>=m) r=mid;
        else l=mid+1;
    }
    return l;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
    int mx=s[n];
    vector<P> ans;
    for(int i=0;i<n;i++){
        int j=search(s[i],i+1,n);
        if(s[j]-s[i]>=m){
            if(s[j]-s[i]<mx){
                ans.clear();
                ans.push_back({i+1,j});
                mx=s[j]-s[i];
            }
            else if(s[j]-s[i]==mx)
                ans.push_back({i+1,j});
        }
    }
    for(auto x:ans){
        printf("%d-%d\n",x.first,x.second);
    }
    return 0;
}