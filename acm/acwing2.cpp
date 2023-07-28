#include <iostream>
using namespace std;
const int maxn=1010;
const int inf=1<<30;

int f[maxn],v[maxn],w[maxn],n,m;

int main(){
	while(cin>>n>>m){
		for(int i=1;i<maxn;i++)
			f[i]=-inf;
		for(int i=1;i<=n;i++)
			cin>>v[i]>>w[i];
		for(int i=1;i<=n;i++){
			for(int j=m;j>=v[i];j--)
				f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
		cout << f[m] << endl;
	}
	return 0;
}