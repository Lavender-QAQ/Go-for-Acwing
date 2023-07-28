#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

int p,in,m;
priority_queue<int> l;
priority_queue<int,vector<int>,greater<int> > s;

int main(){
    scanf("%d",&p);
    while(p--){
        while(!l.empty()) l.pop();
        while(!s.empty()) s.pop();
        scanf("%d%d",&in,&m);
        printf("%d %d\n",in,(int)ceil(m/2.0));
        int out=0;
        for(int i=1;i<=m;i++){
            scanf("%d",&in);
            if(!s.size())
                s.push(in);
            else if(in>=s.top())
                s.push(in);
            else
                l.push(in);
            while(l.size()>s.size()){
                int x=l.top();l.pop();
                s.push(x);
            }
            while(s.size()-1>l.size()){
                int x=s.top();s.pop();
                l.push(x);
            }
            if(i%2){
                out++;
                if(out%10!=1)
                    printf(" ");
                if(out%10==1&&out!=1)
                    printf("\n");
                printf("%d",s.top());
            }
        }
        if(m%10!=0)
            printf("\n");
    }
    return 0;
}
