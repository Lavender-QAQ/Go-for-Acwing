#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=110;

int p[20];

vector<int> mul(vector<int>& a,int b){
    vector<int> ans;
    int t=0;
    for(int i=0;i<a.size();i++){
        t+=a[i]*b;
        ans.push_back(t%10);
        t/=10;
    }
    while(t) ans.push_back(t%10),t/=10;
    return ans;
}

int main(){
    string s;
    vector<int> v;
    cin>>s;
    for(int i=(int)s.length()-1;i>=0;i--)
        v.push_back(s[i]-'0');
    memset(p,0,sizeof p);
    for(auto x:v) p[x]++;
    vector<int> ans=mul(v,2);
    for(auto x:ans) p[x]--;
    bool flag=true;
    for(int i=0;i<=9;i++)
        if(p[i]!=0){
            flag=false;
            break;
        }
    if(flag) puts("Yes");
    else puts("No");
    for(int i=(int)ans.size()-1;i>=0;i--)
        cout << ans[i];
    cout << endl;
    return 0;
}
