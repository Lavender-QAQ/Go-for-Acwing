#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<ll,vector<ll>,greater<ll> > que;

int main(){
	int n,in;
	while(scanf("%d",&n)!=EOF){
		while(!que.empty()) que.pop();
		while(n--){
			scanf("%d",&in);
			que.push(in);
		}
		ll ans=0,sum=0;
		while(que.size()>1){
			ll t1=que.top();que.pop();
			ll t2=que.top();que.pop();
			sum+=t1+t2;
			que.push(t1+t2);
		}
		printf("%lld\n",sum);
	}
	return 0;
}