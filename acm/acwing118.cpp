#include <iostream>
using namespace std;
const int maxn=1000;

int mp[maxn][maxn];

void dfs(int n){
    if(n==0){
        mp[0][0]=1;
        return;
    }
    dfs(n-1);
    int len=1;
    for(int i=0;i<n-2;i++)
        len*=3;
    int sx[4]={0,1,2,2},sy[4]={2,1,0,2};
    for(int k=0;k<4;k++)
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                mp[i+sx[k]*len][j+sy[k]*len]=mp[i][j];
}

int main(){
    int n;
    dfs(7);
    while(cin>>n&&n!=-1){
        int len=1;
        for(int i=0;i<n-1;i++)
            len*=3;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(mp[i][j]==1)
                    cout << 'X';
                else
                    cout << ' ';
            }
            cout << endl;
        }
        cout << '-' << endl;
    }
    return 0;
}

