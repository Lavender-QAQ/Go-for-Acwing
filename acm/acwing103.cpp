#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=(int)2e5+10;

int a[maxn],b[maxn],c[maxn],s[maxn];

vector<int> v;
int getid(int x){
    return (int)(lower_bound(v.begin(),v.end(),x)-v.begin());
}

int main(){
    int n,m;
    while(~scanf("%d",&n)){
        memset(s,0,sizeof(s));
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]),v.push_back(a[i]);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]),v.push_back(b[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&c[i]),v.push_back(c[i]);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int i=0;i<n;i++)
           s[getid(a[i])]++;
        int mx_b=s[getid(b[0])],mx_c=s[getid(c[0])],index=0;
        for(int i=1;i<m;i++){
            int x=s[getid(b[i])];
            if(mx_b==x){
                int y=s[getid(c[i])];
                if(mx_c<y) mx_c=y,index=i;
            }
            else if(mx_b<x) mx_b=x,mx_c=s[getid(c[i])],index=i;
        }
        printf("%d\n",index+1);
    }
    return 0;
}
