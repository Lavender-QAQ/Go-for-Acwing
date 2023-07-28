#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int> > que;

int main(){
	ios::sync_with_stdio(false);
	vector<int> v;
	for(int i=0;i<10;i++) v.push_back(i);
	for(auto x:v){
		cout << x << ' ';
	}
	cout << endl;
	return 0;
}
