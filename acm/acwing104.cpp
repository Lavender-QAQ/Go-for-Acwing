#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int *a=new int[n+10];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+1+n);
        int pos=a[(1+n)/2];
        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=abs(a[i]-pos);
        cout << ans << endl;
    }
    return 0;
}
