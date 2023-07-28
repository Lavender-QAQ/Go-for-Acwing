#include <iostream>
#include <iomanip>
using namespace std;

const int maxn = 2e5+10;

int a[maxn];

int main(){
    int n,k,l=0,r=0;
    long long sum=0;
    int len=1<<30;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    while(r<n){
        sum+=a[r];
        while(sum-a[l]>=k) sum-=a[l],l++;
        if(sum>=k) len=min(len,r-l+1);
        r++;
    }
    if(len==1<<30){
        cout << "-1" << endl;
    } else {
        cout << len << endl;
    }
    return 0;
}