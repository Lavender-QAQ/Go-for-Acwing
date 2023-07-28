#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n;
vector<int> v;

void dfs(int d,int state){
    if(d==n){
        for(auto a:v)
            printf("%d ",a);
        printf("\n");
    }
    for(int i=0;i<n;i++)
        if(!(state&(1<<i))){
            v.push_back(i+1);
            dfs(d+1,state|1<<i);
            v.pop_back();
        }
}

int main(){
    while(~scanf("%d",&n)){
        v.clear();
        dfs(0,0);
    }
    return 0;
}