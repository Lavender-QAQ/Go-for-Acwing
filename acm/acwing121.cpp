#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> P;
const int maxn=1010;

int c,n;
P p[maxn];
vector<int> v;
int sum[maxn][maxn];

int getid(int x){
    return (int)(lower_bound(v.begin(),v.end(),x)-v.begin());
}

bool judge(int len){
    for(int x1=0,x2=1;x2<v.size();x2++){
        while(v[x2]-v[x1+1]+1>len) x1++;
        for(int y1=0,y2=1;y2<v.size();y2++){
            while(v[y2]-v[y1+1]+1>len) y1++;
            if(sum[x2][y2]-sum[x2][y1]-sum[x1][y2]+sum[x1][y1]>=c)
                return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>c>>n;
    v.push_back(0);
    for(int i=0;i<n;i++)
        cin>>p[i].first>>p[i].second,v.push_back(p[i].first),v.push_back(p[i].second);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<n;i++){
        int x=getid(p[i].first);
        int y=getid(p[i].second);
        sum[x][y]++;
    }
    for(int i=1;i<v.size();i++)
        for(int j=1;j<v.size();j++)
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    int l=1,r=10000;
    while(l<r){
        int mid=(l+r)>>1;
        if(judge(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout << l << endl;
    return 0;
}
