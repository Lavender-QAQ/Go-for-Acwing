#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int mp[150][150];

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int d=0,x=0,y=0;
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n*m;i++){
			//cout << x << ' ' << y << ' ' << i <<endl;
			mp[x][y]=i;
			if(i==n*m)
				break;
			while(x+dx[d]<0||x+dx[d]>=n||y+dy[d]<0||y+dy[d]>=m||mp[x+dx[d]][y+dy[d]]!=0)
				d++,d%=4;
			x+=dx[d],y+=dy[d];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(j) printf(" ");
				printf("%d",mp[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}