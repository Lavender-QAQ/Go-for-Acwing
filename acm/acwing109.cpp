#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=500050;
const int inf=0x3f;

int k,n,m,t,ans;
int a[maxn],t[maxn];
void merge(int l,int mid,int r){

}

bool check(int l,int r){
    int cnt=0;
    sort(a+l,a+r+1);
    while(l<r){
        if(cnt==m)
            return true;
        if(pow(1ll*(a[l]-a[r]),1ll*2)>t)
            return false;
        l++,r--,cnt++;
    }
    return true;
}

int main(){
    cin>>k;
    while(k--){
        memset(a,inf,sizeof(a));
        ans=0;
        cin>>n>>m>>t;
        for(int i=0;i<n;i++)
            cin>>a[i];
        int i=0,step=0;
        while(i<n){
            while(check(i,i+(1<<step))) step++;
            for(int j=i+(1<<max(0,(step-1)));j<=i+(1<<step);j++){
                if(!check(i,j)){
                    i=j,step=0,ans++;
                    break;
                }
            }
            //cout << i << endl;
        }
        cout << ans << endl;
    }
    return 0;
}

