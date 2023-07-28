#include <iostream>
#include <vector>
using namespace std;
const int maxn=10010;

struct node{
    int val;
    node *l,*r;
    node(int val){
        this->val=val;
        this->l=nullptr;
        this->r=nullptr;
    }
};

int a[maxn],n;
vector<int> pre,post;

void build(node*& u,const int& x){
    if(u==nullptr){
        u=new node(x);
        return;
    }
    if(x<u->val) build(u->l,x);
    else build(u->r,x);
}

void reverse(node*& u){
    if(u==nullptr) return;
    swap(u->l,u->r);
    reverse(u->l);
    reverse(u->r);
}

void pre_order(node* u){
    if(u==nullptr) return;
    pre.push_back(u->val);
    pre_order(u->l);
    pre_order(u->r);
}

void post_order(node* u){
    if(u==nullptr) return;
    post_order(u->l);
    post_order(u->r);
    post.push_back(u->val);
}

bool judge(){
    if(pre.size()!=n) return false;
    for(int i=0;i<n;i++)
        if(a[i]!=pre[i]) return false;
    return true;
}

int main(){
    cin>>n;
    node* root=nullptr;
    for(int i=0;i<n;i++) cin>>a[i],build(root,a[i]);
    pre_order(root);
    if(judge()){
        puts("YES");
        post_order(root);
        for(int i=0;i<post.size();i++){
            if(i) cout << ' ';
            cout << post[i];
        }
        cout << endl;
    }
    else{
        pre.clear();
        reverse(root);
        pre_order(root);
        if(judge()){
            puts("YES");
            post_order(root);
            for(int i=0;i<post.size();i++){
                if(i) cout << ' ';
                cout << post[i];
            }
            cout << endl;
        }
        else puts("NO");
    }
    return 0;
}