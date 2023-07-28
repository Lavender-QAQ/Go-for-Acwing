#include <iostream>
#include <queue>
using namespace std;

queue<int> que;

bool is_prime(int n){
    if(n<=1) return false;
    for(int i=2;i<=n/i;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    int n,d;
    while(~scanf("%d",&n)&&n>=0){
        scanf("%d",&d);
        if(!is_prime(n)) puts("No");
        else{
            queue<int> que;
            while(n){
                que.push(n%d);
                n/=d;
            }
            n=0;
            while(!que.empty()){
                n=n*d+que.front();
                que.pop();
            }
            if(!is_prime(n)) puts("No");
            else puts("Yes");
        }
    }
    return 0;
}