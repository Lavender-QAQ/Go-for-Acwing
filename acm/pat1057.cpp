#include <iostream>
#include <stack>
using namespace std;
const int maxn=100010;

int tree[maxn];

int lowbit(int x){
    return (-x)&x;
}

void add(int x,int val){
    while(x<maxn){
        tree[x]+=val;
        x+=lowbit(x);
    }
}

int sum(int x){
    int ans=0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}

int search(int x){
    int l=0,r=maxn-1;
    while(l<r){
        int mid=l+r>>1;
        if(sum(mid)>=x) r=mid;
        else l=mid+1;
    }
    return l;
}

int main(){
    stack<int> s;
    int n,val;
    string op;
    cin>>n;
    while(n--){
        cin>>op;
        if(op=="Pop"){
            if(!s.empty()){
                printf("%d\n",s.top());
                add(s.top(),-1);
                s.pop();
            }
            else puts("Invalid");
        }
        else if(op=="PeekMedian"){
            if(!s.empty()){
                printf("%d\n",search((s.size()+1)/2));
            }
            else puts("Invalid");
        }
        else{
            cin>>val;
            s.push(val);
            add(val,1);
        }
    }
    return 0;
}