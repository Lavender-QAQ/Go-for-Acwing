#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1010;

int n,R,ans=0;

struct Node{
    int father,size,sum;
    double avg;
    void update(int sum,int size){
        this->sum+=sum;
        this->size+=size;
        this->avg=(double)this->sum/this->size;
    }
}node[maxn];

int find_max(){
    int id=0;
    double avg=-1;
    for(int i=1;i<=n;i++){
        if(i!=R&&node[i].avg>avg)
            id=i,avg=node[i].avg;
    }
    return id;
}

int main(){
    cin>>n>>R;
    for(int i=1;i<=n;i++){
        cin>>node[i].sum;
        node[i].size=1;
        node[i].avg=node[i].sum;
        ans+=node[i].sum;
    }
    for(int i=0,a,b;i<n-1;i++){
        cin>>a>>b;
        node[b].father=a;
    }
    for(int i=0;i<n-1;i++){
        int f=find_max();
        ans+=node[f].sum*node[node[f].father].size;
        for(int j=1;j<=n;j++){
            if(node[j].father==f)
                node[j].father=node[f].father;
        }
        node[node[f].father].update(node[f].sum,node[f].size);
        node[f].avg=-1;
    }
    cout << ans << endl;
    return 0;
}
