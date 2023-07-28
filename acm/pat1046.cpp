#include <iostream>
using namespace std;
const int maxn=2e5+10;

int d[maxn],n,m,sum,s[maxn];

int main(){
    int a,b;
    scanf("%d",&n);
    sum=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]),sum+=d[i],s[i]=s[i-1]+d[i];
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        printf("%d\n",min(s[b-1]-s[a-1],sum-(s[b-1]-s[a-1])));
    }
    return 0;
}