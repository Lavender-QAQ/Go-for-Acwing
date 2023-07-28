#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T;
char c[5][5];
int a[5][5],mp[5][5],ans;
int dx[]={0,-1,1,0,0},dy[]={0,0,0,-1,1};

void turn(int x,int y){
    for(int i=0;i<5;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||nx>=5||ny<0||ny>=5)
            continue;
        mp[nx][ny]=!mp[nx][ny];
    }
}

int judge(){
    ans=1<<30;
    for(int i=0;i<(1<<5);i++){
        memcpy(mp,a,sizeof(a));
        int res=0,flag=1;
        for(int j=0;j<5;j++)
            if(i>>j&1)
                turn(0,j),res++;
        for(int j=1;j<=4;j++)
            for(int k=0;k<5;k++)
                if(mp[j-1][k]==0)
                    turn(j,k),res++;
        for(int j=0;j<5;j++)
            if(mp[4][j]==0)
                flag=0;
        if(flag)
            ans=min(ans,res);
    }
    if(ans>6)
        return -1;
    else
        return ans;
}

int main(){
    cin>>T;
    while(T--){
        for(int i=0;i<5;i++)
            cin>>c[i];
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                a[i][j]=c[i][j]=='1'?1:0;
        cout  << judge() << endl;
    }
    return 0;
}