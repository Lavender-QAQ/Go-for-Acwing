#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=1010;
typedef pair<int,int> P;

P s[maxn];
int n;

bool cmp(P& a,P& b){
    return a.first*a.second<b.first*b.second;
}

vector<int> mul(vector<int>& a,int b){
    vector<int> ans;
    int t=0;
    for(auto x:a){
        t+=x*b;
        ans.push_back(t%10);
        t/=10;
    }
    while(t) ans.push_back(t%10),t/=10;
    return ans;
}

vector<int> div(vector<int>& a,int b){
    vector<int> ans;
    bool flag=false;
    int t=0;
    for(int i=(int)a.size()-1;i>=0;i--){
        t=t*10+a[i];
        int x=t/b;
        if(x||flag){
            flag=true;
            ans.push_back(x);
        }
        t%=b;
    }
    return vector<int>(ans.rbegin(),ans.rend());
}

vector<int> max_v(const vector<int>& a,const vector<int>& b){
    if(a.size()>b.size())
        return a;
    else if(b.size()>a.size())
        return b;
    else
        return vector<int>(a.rbegin(),a.rend())>vector<int>(b.rbegin(),b.rend())?a:b;
}

int main(){
    cin>>n;
    for (int i = 0; i <= n; i++)
        cin >> s[i].first >> s[i].second;
    sort(s + 1, s + n + 1, cmp);
    vector<int> ans(1, 0), v(1, 1);
    for (int i = 0; i <= n; i++) {
        if (i)
            ans = max_v(ans, div(v, s[i].second));
        v = mul(v, s[i].first);
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
