#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<int> post,in;
int n;

struct node{
    int val;
    node* l;
    node* r;
};

node* dfs(int pl,int pr,int il,int ir){
    node *u=new node;
    u->val=post[pr];
    int t=-1;
    for(int i=0;i<in.size();i++)
        if(in[i]==post[pr]){
            t=i;
            break;
        }
    int l=t-il,r=ir-t;
    if(l==0) u->l=nullptr;
    else u->l=dfs(pr-l-r,pr-r-1,il,t-1);
    if(r==0) u->r=nullptr;
    else u->r=dfs(pr-r,pr-1,t+1,ir);
    return u;
}

void bfs(node* root){
    queue<node*> que;
    que.push(root);
    while(!que.empty()){
        node* u=que.front();que.pop();
        if(u==root) printf("%d",u->val);
        else printf(" %d",u->val);
        if(u->l!=nullptr) que.push(u->l);
        if(u->r!=nullptr) que.push(u->r);
    }
    puts("");
}

int main(){
    int x;
    cin>>n;
    for(int i=0;i<n;i++) cin>>x,post.push_back(x);
    for(int i=0;i<n;i++) cin>>x,in.push_back(x);
    node* root=dfs(0,n-1,0,n-1);
    bfs(root);
    return 0;
}