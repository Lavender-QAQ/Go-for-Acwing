#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
typedef pair<int,int> P;

struct grade{
    string s;
    int a,c,m,e;
};
vector<grade> v;
vector<P> ans;
unordered_map<string,int> ma,mc,mm,me;
unordered_map<int,char> mp;

void output(string& s){
    if(!ma.count(s)) {
        cout << "N/A" << endl;
        return;
    }
    ans.clear();
    ans.push_back({ma[s],4});
    ans.push_back({mc[s],3});
    ans.push_back({mm[s],2});
    ans.push_back({me[s],1});
    sort(ans.begin(),ans.end(),[](const P& p,const P& q){
        if(p.first==q.first)
            return p.second>q.second;
        else return p.first<q.first;
    });
    cout << ans[0].first << ' ' << mp[ans[0].second] << endl;
}

int main(){
    mp.insert({4,'A'});
    mp.insert({3,'C'});
    mp.insert({2,'M'});
    mp.insert({1,'E'});
    int n,k,a,c,m,e;
    string s;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>s>>c>>m>>e;
        a=c+m+e;
        v.push_back({s,a,c,m,e});
    }
    sort(v.begin(),v.end(),[](const grade& p,const grade& q){
       return p.a>q.a;
    });
    int t=1;
    for(int i=0;i<v.size();i++){
        if(i){
            if(v[i].a<v[i-1].a)
                t=i+1;
        }
        ma.insert({v[i].s,t});
    }
    sort(v.begin(),v.end(),[](const grade& p,const grade& q){
        return p.c>q.c;
    });
    t=1;
    for(int i=0;i<v.size();i++){
        if(i){
            if(v[i].c<v[i-1].c)
                t=i+1;
        }
        mc.insert({v[i].s,t});
    }
    sort(v.begin(),v.end(),[](const grade& p,const grade& q){
        return p.m>q.m;
    });
    t=1;
    for(int i=0;i<v.size();i++){
        if(i){
            if(v[i].m<v[i-1].m)
                t=i+1;
        }
        mm.insert({v[i].s,t});
    }
    sort(v.begin(),v.end(),[](const grade& p,const grade& q){
        return p.e>q.e;
    });
    t=1;
    for(int i=0;i<v.size();i++){
        if(i){
            if(v[i].e<v[i-1].e)
                t=i+1;
        }
        me.insert({v[i].s,t});
    }
    while(k--){
        cin>>s;
        output(s);
    }
    return 0;
}