#include <iostream>
#include <cstdio>
#include <climits>
#include <queue>
using namespace std;
const int N=100010,M=7000010;

queue<int> ql,qr;
priority_queue<int> qn;

int get_max(){
    int x=INT_MIN;
    if(!qn.empty()) x=max(x,qn.top());
    if(!ql.empty()) x=max(x,ql.front());
    if(!qr.empty()) x=max(x,qr.front());
    if(!qn.empty()&&x==qn.top()) qn.pop();
    else if(!ql.empty()&&x==ql.front()) ql.pop();
    else if(!qr.empty()&&x==qr.front()) qr.pop();
    return x;
}

int main(){
    int n,m,q,u,v,t,x,delta=0;
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        qn.push(x);
    }
    for(int i=1;i<=m;i++){
        x=get_max();
        x+=delta;
        int l=int(x*1ll*u/v);
        int r=x-l;
        delta+=q;
        ql.push(l-delta);
        qr.push(r-delta);
        if(i%t==0)
            printf("%d ",x);
    }
    printf("\b\n");
    for(int i=1;i<=n+m;i++){
        x=get_max();
        if(i%t==0)
            printf("%d ",x+delta);
    }
    printf("\b\n");
    return 0;
}