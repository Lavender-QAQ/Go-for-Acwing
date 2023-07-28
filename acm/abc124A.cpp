#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int a,b;
	ios::sync_with_stdio(false);
	while(cin>>a>>b){
		cout << max(2*a-1,max(2*b-1,a+b)) << endl;
	}
	return 0;
}