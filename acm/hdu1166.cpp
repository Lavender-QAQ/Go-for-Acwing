#include<iostream>
#include<cstring>
using namespace std;
const int maxn=50010;

int tree[maxn],n;

inline int lowbit(int x){
    return x&(-x);
}

void add(int x,int val){
    for(int i=x;i<=maxn;i+=lowbit(i))
        tree[i]+=val;
}

int get(int x){
    int sum=0;
    for(int i=x;i;i-=lowbit(i))
        sum+=tree[i];
    return sum;
}


int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    string s;
    int x,y;
    for(int cas=1;cas<=T;cas++){
        cout << "Case " << cas << ":" << endl;
        memset(tree,0,sizeof(tree));
        cin>>n;
        int in;
        for(int i=1;i<=n;i++)
            cin>>in,add(i, in);
        while(cin>>s){
            if (s == "End")
                break;
            else if (s == "Query") {
                cin >> x >> y;
                cout << get(y)-get(x-1) << endl;
            } else if (s == "Add") {
                cin >> x >> y;
                add(x,y);
            } else if (s == "Sub") {
                cin >> x >> y;
                add(x,-y);
            }
        }
    }
    return 0;
}