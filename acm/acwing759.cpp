#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=1e4;
typedef long long ll;

int n;
struct node{
	int l,r,x;
	node(int l,int r,int x):l(l),r(r),x(x){}
	bool operator < (const node& a) const{
		if(x!=a.x) return x<a.x;
		if(l!=a.l) return l<a.l;
		return r<a.r; 
	}
};

vector<node> vx,vy;

ll merge(vector<node>& v){
	ll ans=0;
	vector<node> vv;
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();){
		int j=i;
		while(j<v.size()&&v[i].x==v[j].x) j++;
		int l=v[i].l,r=v[i].r;
		for(int k=i+1;k<j;k++){
			if(r<v[k].l){
				ans+=r-l+1;
				vv.push_back(node(l,r,v[i].x));
				l=v[k].l,r=v[k].r;
			}
			else
				r=max(r,v[k].r);
		}
		ans+=r-l+1;
		vv.push_back(node(l,r,v[i].x));
		i=j;
	}
	v=vv;
	return ans;
}

int main(){
	int x1,y1,x2,y2;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2)
			vy.push_back(node(min(y1,y2),max(y1,y2),x1));
		else
			vx.push_back(node(min(x1,x2),max(x1,x2),y1));
	}
	ll ans=merge(vx)+merge(vy);
	for(int i=0;i<vx.size();i++){
		for(int j=0;j<vy.size();j++){
			if(vy[j].x>=vx[i].l&&vy[j].x<=vx[i].r&&vx[i].x>=vy[j].l&&vx[i].x<=vy[j].r)
				ans--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
