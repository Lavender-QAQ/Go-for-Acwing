#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int st=8*60*60,ed=17*60*60;
const int maxn=3e5+10;

struct person{
    string s;
    int t,val;
    void ver(){
        int a,b,c;
        a=(s[0]-'0')*10+s[1]-'0';
        b=(s[3]-'0')*10+s[4]-'0';
        c=(s[6]-'0')*10+s[7]-'0';
        t=a*60*60+b*60+c;
    }
}p[maxn];

int w[maxn];

int main(){
    int n,k,x,wait=0;
    string s;
    cin>>n>>k;
    if(n==0){
        puts("0.0");
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>s>>x;
        p[i].s=s,p[i].val=x*60;
        p[i].ver();
    }
    sort(p,p+n,[](const person& a,const person& b){
        return a.s<b.s;
    });
    for(int i=n-1;i>=0;i--)
        if(p[i].t>ed)
            n--;
    for(int i=0;i<n;i++)
        if(p[i].t<st){
            wait+=st-p[i].t;
            p[i].t=st;
        }
    for(int i=0;i<k;i++) w[i]=st;
    for(int i=0;i<n;i++){
        int pos=0;
        for(int j=0;j<k;j++)
            if(w[j]<w[pos])
                pos=j;
        if(w[pos]<p[i].t) w[pos]=p[i].t+p[i].val;
        else{
            wait+=w[pos]-p[i].t;
            w[pos]+=p[i].val;
        }
    }
    double ans=(double)wait/60.0/n;
    printf("%.1lf\n",ans);
    return 0;
}