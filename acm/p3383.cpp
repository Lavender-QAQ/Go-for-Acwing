#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1e8+10;
int n,m;

bool flag[maxn];
vector<int> prime;

void run(){
	memset(flag,false,sizeof(false));
	flag[1]=true;
	for(int i=2;i<=1e7;i++){
		if(!flag[i])
			prime.push_back(i);
		for(int j=0;j<prime.size()&&(long long)i*prime[j]<=1e7;j++){
			flag[prime[j]*i]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}

int main(){
	run();
	while(scanf("%d%d",&n,&m)!=EOF){
		int in;
		while(m--){
			scanf("%d",&in);
			if(!flag[in])
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}