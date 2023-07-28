#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=(int)1e5+10;
typedef pair<int,int> P;

int f[maxn],val[maxn];
unordered_set<int> s;
unordered_map<string,int> call;
unordered_map<int,vector<P>> gang;
vector<P> ans;

int convert(const string& s){
    return (s[0]-'A')*26*26+(s[1]-'A')*26+s[2]-'A';
}
string decode(int x){
    string s;
    s+=x/26/26+'A';
    s+=x/26%26+'A';
    s+=x%26+'A';
    return s;
}

int find(int x){
    return f[x]=x==f[x]?x:find(f[x]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,time;
    string s1,s2;
    cin>>n>>k;
    for(int i=0;i<maxn;i++) f[i]=i;
    for(int i=0;i<n;i++){
        cin>>s1>>s2>>time;
        if(s1>s2) swap(s1,s2);
        call[s1+s2]+=time;
    }
    for(auto x:call){
        int a=convert(x.first.substr(0,3)),b=convert(x.first.substr(3,3)),c=x.second;
        int fa=find(a),fb=find(b);
        if(fa!=fb) f[fb]=fa;
        val[a]+=c,val[b]+=c;
        s.insert(a);
        s.insert(b);
    }
    for(auto x:s){
        int fx=find(x);
        gang[fx].push_back({x,val[x]});
    }
    for(auto x:gang){
        auto v=x.second;
        if(v.size()<=2) continue;
        int sum=0;
        for(auto i:v) sum+=i.second;
        if(sum/2<=k) continue;
        sort(v.begin(),v.end(),[](const P& a,const P& b){
            if(a.second==b.second) return a.first<b.first;
            else return a.second>b.second;
        });
        ans.push_back({v[0].first,v.size()});
    }
    cout << ans.size() << endl;
    sort(ans.begin(),ans.end(),[](const P& a,const P& b){
        return a.first<b.first;
    });
    for(auto x:ans){
        cout << decode(x.first) << ' ' << x.second << endl;
    }
}