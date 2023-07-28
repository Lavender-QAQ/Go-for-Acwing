#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct info{
    string s;
    ll in,out;
};

vector<info> v;

int main(){
    int n,a,b,c;
    ll in,out;
    string s;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>s;
        scanf("%d:%d:%d",&a,&b,&c);
        in=a*24*24+b*24+c;
        scanf("%d:%d:%d",&a,&b,&c);
        out=a*24*24+b*24+c;
        v.push_back({s,in,out});
    }
    sort(v.begin(),v.end(),[](const info& a,const info& b){
        return a.in<b.in;
    });
    cout << v[0].s << ' ';
    sort(v.begin(),v.end(),[](const info& a,const info& b){
        return a.out>b.out;
    });
    cout << v[0].s << endl;
    return 0;
}