#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
const int maxn=200010;
const double inf=1e10;

struct Point{
    double x,y;
    int type;
    bool operator < (const Point& a)const{
        return x<a.x;
    }
}p[maxn],t[maxn];

double dist(const Point& a,const Point& b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

double dfs(int l,int r){
    if(l>=r)
        return inf;
    int mid=(l+r)>>1;
    double line=p[mid].x;
    double ans=min(dfs(l,mid),dfs(mid+1,r));
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(p[i].y<=p[j].y)
            t[k++]=p[i++];
        else
            t[k++]=p[j++];
    }
    while(i<=mid) t[k++]=p[i++];
    while(j<=r) t[k++]=p[j++];
    for(i=0,j=l;i<k;i++,j++)
        p[j]=t[i];
    k=0;
    for(i=l;i<=r;i++)
        if(p[i].x>=line-ans&&p[i].x<=line+ans)
            t[k++]=p[i];
    for(i=0;i<k;i++)
        for(j=i-1;j>=0&&t[i].y-t[j].y<=ans;j--)
            if(t[i].type!=t[j].type)
                ans=min(ans,dist(t[i],t[j]));
    return ans;        
}


int main(){
    int T,n;
    cin>>T;
    while(T--){
        memset(p,0,sizeof(p));
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>p[i].x>>p[i].y,p[i].type=0;
        for(int i=n;i<2*n;i++)
            cin>>p[i].x>>p[i].y,p[i].type=1;
        sort(p,p+2*n);
        cout << fixed << setprecision(3) << dfs(0,2*n-1) << endl;
    }
    return 0;
}