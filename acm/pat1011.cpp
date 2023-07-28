#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<double,char> P;

vector<P> v1,v2,v3;

int main(){
    char s[3]={'W','T','L'};
    int T=3;
    double n;
    for(int i=0;i<T;i++){
        cin>>n;
        v1.push_back({n,s[i]});
    }
    for(int i=0;i<T;i++){
        cin>>n;
        v2.push_back({n,s[i]});
    }
    for(int i=0;i<T;i++){
        cin>>n;
        v3.push_back({n,s[i]});
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    printf("%c %c %c ",v1.back().second,v2.back().second,v3.back().second);
    double ans=(0.65*v1.back().first*v2.back().first*v3.back().first-1)*2;
    printf("%.2lf\n",ans);
    return 0;
}