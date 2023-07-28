#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    int id,a,b;
};

bool cmp(const node& p,const node& q){
    if(p.a+p.b==q.a+q.b&&p.a==q.a) return p.id<q.id;
    else if(p.a+p.b==q.a+q.b) return p.a>q.a;
    else return p.a+p.b>q.a+q.b;
}

vector<node> sage,nobleman,foolman,other;

int main(){
    int n,id,a,b,x,y;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        cin>>id>>x>>y;
        if(x>=a&&y>=a){
            if(x>=b&&y>=b) sage.push_back({id,x,y});
            else if(x>=b&&y<b) nobleman.push_back({id,x,y});
            else if(x<b&&y<b&&x>=y) foolman.push_back({id,x,y});
            else other.push_back({id,x,y});
        }
    }
    n=sage.size()+nobleman.size()+foolman.size()+other.size();
    sort(sage.begin(),sage.end(),cmp);
    sort(nobleman.begin(),nobleman.end(),cmp);
    sort(foolman.begin(),foolman.end(),cmp);
    sort(other.begin(),other.end(),cmp);
    cout << n << endl;
    for(auto i:sage)
        printf("%08d %d %d\n",i.id,i.a,i.b);
    for(auto i:nobleman)
        printf("%08d %d %d\n",i.id,i.a,i.b);
    for(auto i:foolman)
        printf("%08d %d %d\n",i.id,i.a,i.b);
    for(auto i:other)
        printf("%08d %d %d\n",i.id,i.a,i.b);
    return 0;
}