#include <iostream>
#include <cstdio>
using namespace std;

int n;

void dfs(int d,int state){
    if(d==n){
        for(int i=0;i<n;i++)
            if(state>>i&1)
                printf("%d ",i+1);
        printf("\n");
    }
    else{
        dfs(d+1,state);
        dfs(d+1,state|(1<<d));
    }
}

int main(){
    while(~scanf("%d",&n)){
        dfs(0,0);
    }
    return 0;
}