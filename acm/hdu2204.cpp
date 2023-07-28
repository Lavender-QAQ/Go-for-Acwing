#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const double eps=1e-8;

vector<int> prime;
ll n;
bool flag[60];

void init(){
	prime.clear();
	memset(flag,true,sizeof(flag));
	flag[1]=false;
	for(int i=2;i<60;i++){
		if(flag[i])
			prime.push_back(i);
		for(int j=0;j<prime.size()&&prime[j]*i<60;j++){
			flag[prime[j]*i]=false;
			if(i%prime[j]==0)
				break;
		}
	}
}

int main(){
	init();
	while(~scanf("%lld",&n)){
		ll ans=1,t;
		int len=prime.size();
		for(int i=0;i<len;i++){
			t=(ll)(pow(n,1.0/prime[i])+eps);
			ans+=t-1;
			if(t<2) break;
			for(int j=i+1;j<len;j++){
				t=(ll)(pow(n,1.0/(prime[i]*prime[j]))+eps);
				ans-=t-1;
				if(t<2) break;
				for(int k=j+1;k<len;k++){
					t=(ll)(pow(n,1.0/(prime[i]*prime[j]*prime[k]))+eps);
					ans+=t-1;
					if(t<2) break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}