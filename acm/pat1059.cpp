#include <iostream>
#include <vector>
using namespace std;
const int maxn=500010;

vector<int> primes;
int flag[maxn];

void get_primes(int n){
    for(int i=2;i<=n;i++){
        if(!flag[i]){
            primes.push_back(i);
            for(int j=i+i;j<=n;j+=i)
                flag[j]=true;
        }
    }
}


void divide(long long n){
    long long a=n;
    for(auto i:primes){
        if(n%i==0){
            if(n!=a) printf("*");
            int s=0;
            while(n%i==0){
                n/=i;
                s++;
            }
            if(s==1) printf("%d",i);
            else printf("%d^%d",i,s);
        }
    }
    if(n>1){
        if(n!=a) printf("*");
        printf("%lld",n);
    }
}

int main(){
    get_primes(maxn);
    long long x;
    scanf("%lld",&x);
    if(x==1){
        printf("1=1\n");
        return 0;
    }
    printf("%lld=",x);
    divide(x);
    puts("");
    return 0;
}