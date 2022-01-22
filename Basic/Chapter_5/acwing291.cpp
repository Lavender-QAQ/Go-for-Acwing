#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 12;

long long f[maxn][1<<maxn];
bool judge[1<<maxn];

int main(){
    int n,m;
    while(cin>>n>>m,n||m){
        memset(f,0,sizeof f);
        for(int state=0;state<(1<<n);state++){
            judge[state]=true;
            int cnt=0;
            for(int i=0;i<n;i++){
                if((state>>i)&1){
                    if(cnt&1){
                        judge[state]=false;
                        break;
                    }
                    cnt=0;
                }
                else cnt++;
            }
            if(cnt&1) judge[state]=false;
        }
        f[0][0]=1;
        for(int i=1;i<=m;i++)
            for(int j=0;j<1<<n;j++)
                for(int k=0;k<1<<n;k++){
                    if((j&k)==0&&judge[j|k])
                        f[i][j]+=f[i-1][k];
                }
        cout << f[m][0] << endl;
    }
    return 0;
}