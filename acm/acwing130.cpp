#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=120010;

bool p[maxn];
int powers[maxn],primes[maxn],cnt=0;

void init(int n){
    fill(p,p+n,true);
    for(int i=2;i<=n;i++){
        if(p[i]){
            primes[cnt++]=i;
            for(int j=i*2;j<=n;j+=i)
                p[j]=false;
        }
    }
}

int get(int n,int p){
    int s=0;
    while(n){
        s+=n/p;
        n/=p;
    }
    return s;
}

inline void mul(vector<ll>& a,int b){
    ll t=0;
    for(int i=0;i<a.size();i++){
        a[i]=a[i]*b+t;
        t=a[i]/100000000;
        a[i]%=100000000;
    }
    while(t){
        a.push_back(t%100000000);
        t/=100000000;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    init(2*n);
    for(int i=0;i<cnt;i++)
        powers[primes[i]]=get(2*n,primes[i])-2*get(n,primes[i]);
    int k=n+1;
    for(int i=0;i<cnt&&primes[i]<=k;i++){
        int s=0;
        while(k%primes[i]==0){
            k/=primes[i];
            s++;
        }
        powers[primes[i]]-=s;
    }
    vector<ll> ans;
    ans.push_back(1);
    for(int i=0;i<2*n;i++){
        while(powers[i]){
            mul(ans,i);
            powers[i]--;
        }
    }
    printf("%lld",ans.back());
    for(int i=(int)ans.size()-2;i>=0;i--)
        printf("%08lld",ans[i]);
    printf("\n");
    return 0;
}