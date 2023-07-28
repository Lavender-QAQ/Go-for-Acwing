#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
const int maxn=1e6+10;

vector<P> v;
int e[maxn],ne[maxn];

int main(){
    int n,head,a,b,c;
    bool flag=false;
    scanf("%d%d",&n,&head);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        e[a]=b,ne[a]=c;
        if(a==head) flag=true;
    }
    if(!flag){
        puts("0 -1");
        return 0;
    }
    for(int i=head;i!=-1;i=ne[i])
        v.push_back({i,e[i]});
    sort(v.begin(),v.end(),[](const P& a,const P& b){
        return a.second<b.second;
    });
    printf("%d %05d\n",(int)v.size(),v[0].first);
    n=(int)v.size();
    for(int i=0;i<n;i++){
        if(i==n-1) printf("%d %d -1\n",v[i].first,v[i].second);
        else printf("%05d %d %05d\n",v[i].first,v[i].second,v[i+1].first);
    }
    return 0;
}