#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=(int)1e5+10;
int a[maxn],b[maxn],n;
int ans=0,la,lb,ra,rb,sa,sb,count1,count2;

int cal(){
	ans=sa=sb=0;
	for(int i=0;i<n;i++)
		if(a[i]==1){
			la=i;
			break;
		}
	for(int i=n;i>=0;i--)
		if(a[i]==1){
			ra=i;
			break;
		}
	for(int i=0;i<n;i++)
		if(b[i]==1){
			lb=i;
			break;
		}
	for(int i=n;i>=0;i--)
		if(b[i]==1){
			rb=i;
			break;
		}
	for(int i=la;i<=ra;i++)
		if(!a[i]) sa++;
	for(int i=lb;i<=rb;i++)
		if(!b[i]) sb++;
	if(count1==0)
		return max(0,rb-lb-1);
	if(count2==0)
		return max(0,ra-la-1);
	if(count1==1&&count2==1)
		return max(0,abs(ra-lb)-1);

}

int main(){
	while(scanf("%d",&n)!=EOF){
		count1=count2=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i])
				count1++;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
			if(b[i])
				count2++;
		}
		printf("%d\n",cal());
	}
	return 0;
}
