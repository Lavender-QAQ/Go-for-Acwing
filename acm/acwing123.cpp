#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=10010;

int x[maxn],y[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&x[i],&y[i]);
    sort(x,x+n);
    sort(y,y+n);
    for(int i=0;i<n;i++)
        x[i]=x[i]-i;
    sort(x,x+n);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(x[i]-x[n/2]);
        ans+=abs(y[i]-y[n/2]);
    }
    printf("%d\n",ans);
    return 0;
}
