#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<double,double> P;

vector<P> v;

int main(){
    int n;
    double c,D,d,a,b;
    cin>>c>>D>>d>>n;
    for(int i=0;i<n;i++)
        cin>>a>>b,v.push_back({a,b});
    v.push_back({0,D});
    sort(v.begin(),v.end(),[](const P& a,const P& b){
        return a.second<b.second;
    });
    if(v[0].second!=0){
        printf("The maximum travel distance = %.2lf\n",0.00);
        return 0;
    }
    double pos=0,now=c;
    int k=0;
    double ans=0;
    if(c*d>=D){
        printf("%.2lf",ans);
        return 0;
    }
    k=0,pos=0;
    now=0;
    while(pos<D){
        //printf("pos=%d\n",(int)pos);
        double t=v[k].first;
        int id=-1;
        for(int i=k+1;i<v.size()&&v[i].second<=pos+c*d;i++)
            if(v[i].first<t){
                t=v[i].first,id=i;
                break;
            }
        if(id==-1){
            t=1e9;
            for(int i=k+1;i<v.size()&&v[i].second<=pos+c*d;i++)
                if(v[i].first<t) t=v[i].first,id=i;
            if(id==-1){
                printf("%.2lf\n",pos);
                printf("The maximum travel distance = %.2lf\n",pos+c*d);
                return 0;
            }
            ans+=(c-now)*v[k].first;
            now=c-(v[id].second-v[k].second)/d;
            pos=v[id].second;
            k=id;
        }
        else{
            ans+=(v[id].second-pos-now*d)/d*v[k].first;
            now=0;
            pos=v[id].second;
            k=id;
        }
    }
    printf("%.2lf\n",ans);
    return 0;
}