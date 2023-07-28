#include <iostream>
#include <cstdio>
using namespace std;

int n,m;

void dfs(int d,int s,int state){
    if(s==0){
        for(int i=0;i<n;i++)
            if(state>>i&1)
                printf("%d ",i+1);
        printf("\n");
        return;
    }
    if(d==n)
        return;
    dfs(d+1,s-1,state|(1<<d));
    dfs(d+1,s,state);
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        dfs(0,m,0);
    }
    return 0;
}