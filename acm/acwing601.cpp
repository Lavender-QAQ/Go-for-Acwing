#include <iostream>
using namespace std;

int main(){
	int n,m;
	ios::sync_with_stdio(false);
	while(cin>>m>>n){
		int *a=new int[n+10];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int ans=0;
		for(int i=n-1;i>=0;i--){
			if(m==0)
				break;
			if(a[i]>m)
				continue;
			ans+=m/a[i];
			m%=a[i];
		}
		cout << ans << endl;
	}
	return 0;
}