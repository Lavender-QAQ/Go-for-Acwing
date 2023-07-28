#include <iostream>
using namespace std;
const int maxn=1000010;

long long a[maxn],b[maxn],t[maxn];

int main(){
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++) cin>>b[i];
    int i=0,j=0,k=0;
    while(i<n&&j<m){
        if(a[i]<=b[j]) t[k++]=a[i++];
        else t[k++]=b[j++];
    }
    while(i<n) t[k++]=a[i++];
    while(j<m) t[k++]=b[j++];
    cout << t[(n+m-1)/2] << endl;
    return 0;
}