#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=200000;
typedef long long ll;

ll a[maxn];
int n,k;
vector<ll> pre,v;

int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		pre.clear(),v.clear();
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
				v.push_back(a[i]+a[j]);
		sort(v.rbegin(),v.rend());
		ll sum=0;
		for(int i=0;i<v.size();i++){
			sum+=v[i];
			pre.push_back(sum);
		}
		printf("%lld\n",pre[k-1]);
	}
	return 0;
}