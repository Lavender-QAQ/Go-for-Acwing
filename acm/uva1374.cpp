#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn=1010;
int maxd,target;
int a[maxn];

bool dfs(int d,int ans,int cnt){
	if(d==maxd)
		return ans==target?true:false;
	int mx=-1;
	for(int i=0;i<=cnt;i++)
		mx=max(mx,a[i]);
	if(mx*pow(2,maxd-d)<target)
		return false;
	for(int i=cnt;i>=0;i--){
		cnt++;
		a[cnt]=ans+a[i];
		if(dfs(d+1,a[cnt],cnt))
			return true;
		a[cnt]=ans-a[i];
		if(dfs(d+1,a[cnt],cnt))
			return true;
		cnt--;//回溯
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>target&&target){
		for(maxd=0;;maxd++){
			a[0]=1;
			if(dfs(0,1,0)){
				cout << maxd << endl;
				break;
			}
		}
	}
	return 0;
}