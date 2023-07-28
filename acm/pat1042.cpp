#include <iostream>
#include <vector>
using namespace std;
typedef pair<char,int> P;

const char ch[4]={'S','H','C','D'};
int mov[110];

int main(){
    int k;
    cin>>k;
    vector<P> v;
    for(int i=0;i<4;i++)
        for(int j=1;j<=13;j++)
            v.push_back({ch[i],j});
    v.push_back({'J',1});
    v.push_back({'J',2});
    for(int i=0;i<54;i++) cin>>mov[i];
    vector<P> a(v.size());
    while(k--){
        for(int i=0;i<54;i++)
            a[mov[i]-1]=v[i];
        v=a;
    }
    for(int i=0;i<v.size();i++){
        if(i) cout << ' ';
        cout << v[i].first << v[i].second;
    }
    cout << endl;
    return 0;
}