#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int main(){
    int n;
    while(~scanf("%d",&n)){
        ll *a=new ll[n+10]();
        ll *b=new ll[n+10]();
        ll plus=0,minus=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],b[i]=a[i]-a[i-1];
        for(int i=2;i<=n;i++){
            if(b[i]<0)
                minus+=b[i];
            else if(b[i]>0)
                plus+=b[i];
        }
        printf("%lld\n",max(abs(minus),plus));
        printf("%lld\n",abs(minus+plus)+1);
    }
    return 0;
}