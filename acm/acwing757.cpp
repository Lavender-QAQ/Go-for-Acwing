#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=(int)1e5;
typedef pair<int,int> P;

P s1[maxn],s2[maxn];

bool cmp(P a,P b){
    return a.first>b.first;
}

int main(){
    ios::sync_with_stdio(false);
    int n,m,k,in,mx;
    while(cin>>n>>m){
        k=1,mx=0;
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        for(int i=0;i<n;i++){
            if(m%2==0)
                k=!k;
            for(int j=0;j<m;j++){
                cin>>in;
                mx=max(mx,in);
                if(k)
                    s1[in].first++,s1[in].second=i;
                else
                    s2[in].first++,s2[in].second=i;
                k=!k;
            }
        }
        sort(s1,s1+mx+1,cmp);
        sort(s2,s2+mx+1,cmp);
        if(s1[0].second==s2[0].second)
            cout << min(n*m-s1[1].first-s2[0].first,n*m-s1[0].first-s2[1].first) << endl;
        else
            cout << n*m-s1[0].first-s2[0].first << endl;
    }
    return 0;
}

