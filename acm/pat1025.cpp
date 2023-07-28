#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef pair<long long,int> P;

struct person{
    long long id;
    int final,num,local;
};
unordered_map<long long,person> mp;

vector<P> total;
vector<person> ans;

int main(){
    int T,n,score;
    long long id;
    vector<P> v;
    cin>>T;
    for(int k=1;k<=T;k++){
        v.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>id>>score;
            v.push_back({id,score});
            total.push_back({id,score});
            mp[id].id=id;
            mp[id].num=k;
        }
        sort(v.begin(),v.end(),[](const P& a,const P& b){
           if(a.second==b.second) return a.first<b.first;
           else return a.second>b.second;
        });
        int cnt=1;
        for(int i=0;i<v.size();i++){
            if(i>0&&v[i].second!=v[i-1].second)
                cnt=i+1;
            mp[v[i].first].local=cnt;
        }
    }
    sort(total.begin(),total.end(),[](const P& a,const P& b){
        if(a.second==b.second) return a.first<b.first;
        else return a.second>b.second;
    });
    int cnt=1;
    for(int i=0;i<total.size();i++){
        if(i>0&&total[i].second!=total[i-1].second)
            cnt=i+1;
        mp[total[i].first].final=cnt;
    }
    for(auto it:mp) ans.push_back(it.second);
    sort(ans.begin(),ans.end(),[](const person& a,const person& b){
        if(a.final==b.final)
            return a.id<b.id;
        else return a.final<b.final;
    });
    cout << ans.size() << endl;
    for(auto it:ans)
        printf("%013lld %d %d %d\n",it.id,it.final,it.num,it.local);
    return 0;
}