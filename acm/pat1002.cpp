#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;

double a[maxn],b[maxn];
vector<int> v;

int main(){
    int k,n;
    double x;
    scanf("%d",&k);
    while(k--){
        scanf("%d %lf",&n,&x);
        a[n]=x;
        v.push_back(n);
    }
    scanf("%d",&k);
    while(k--){
        scanf("%d %lf",&n,&x);
        b[n]=x;
        v.push_back(n);
    }
    sort(v.rbegin(),v.rend());
    v.erase(unique(v.begin(),v.end()),v.end());
    n=0;
    int ans=0;
    for(auto t:v)
        if(a[t]+b[t]!=0)
            ans++;
    printf("%d",ans);
    for(auto t:v){
        if(a[t]+b[t]!=0)
            printf(" %d %.1lf",t,a[t]+b[t]);
    }
    puts("");
    return 0;
}

