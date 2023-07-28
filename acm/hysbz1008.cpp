#include <iostream>
using namespace std;
const int mod=100003;

long long pow_mod(long long a,long long i,long long n){
    if(i==0)
        return 1%n;
    long long t=pow_mod(a,i>>1,n);
    t=t*t%n;
    if(i&1) t=t*a%n;
    return t;
}

int main(){
    long long n,m;
    while(cin>>m>>n){
        long long ans=(pow_mod(m,n,mod)-(m*pow_mod(m-1,n-1,mod))%mod+mod)%mod;
        cout << ans << endl;
    }
    return 0;
}
