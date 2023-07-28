#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1010;
const int eps=1e-6;
typedef pair<double,double> P;

int n,d;
P a[maxn];

bool cmp(P& a,P& b){
    return a.second<b.second;
}

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>d){
        double x,y;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            if(d*d-y*y<0){
                cout << -1 << endl;
                return 0;
            }
            else
                a[i]={x-sqrt(d*d-y*y),x+sqrt(d*d-y*y)};
        }
        sort(a,a+n,cmp);
        double pos=-(1<<30);
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i].first>pos+eps)
                ans++,pos=a[i].second;
        }
        cout << ans << endl;
    }
    return 0;
}