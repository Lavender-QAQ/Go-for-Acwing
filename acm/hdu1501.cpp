#include <iostream>
#include <cstring>
using namespace std;

string a,b,c;

int vis[300][300],ans;


void dfs(int x,int y,int z){
    if(z==c.length()&&x==a.length()&&y==b.length()) {
        ans=1;
        return;
    }
    if(c[z]!=a[x]&&c[z]!=b[y])
        return;

    if(vis[x][y])
        return;
    vis[x][y]=1;

    if(c[z]==a[x])
        dfs(x+1,y,z+1);
    if(c[z]==b[y])
        dfs(x,y+1,z+1);
}


int main()
{
    int cas;
    while(cin>>cas){
        for(int cot=0;cot<cas;cot++){
            memset(vis,0,sizeof(vis));
            ans=0;
            cin>>a>>b>>c;
            dfs(0,0,0);
            if(ans)
                cout << "yes" <<endl;
            else
                cout << "no" << endl;
        }

    }
    return 0;
}