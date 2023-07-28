#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void add(vector<int>& v){
    vector<int> a=v,b=v;
    reverse(b.begin(),b.end());
    v.clear();
    int t=0;
    for(int i=0;i<a.size();i++){
        t+=a[i]+b[i];
        v.push_back(t%10);
        t/=10;
    }
    while(t) v.push_back(t%10),t/=10;
}

bool judge(vector<int>& v){
    int n=(int)v.size();
    for(int i=0;i<n;i++){
        if(v[i]!=v[n-1-i])
            return false;
    }
    return true;
}

int main(){
    string s;
    int k;
    vector<int> v;
    cin>>s>>k;
    for(int i=(int)s.length()-1;i>=0;i--)
        v.push_back(s[i]-'0');
    if(k==0){
        cout << s << endl;
        cout << k << endl;
    }
    if(judge(v)){
        cout << s << endl;
        puts("0");
        return 0;
    }
    for(int i=1;i<=k;i++){
        add(v);
        if(judge(v)){
            for(auto x:v) cout << x;
            cout << endl;
            cout << i << endl;
            break;
        }
        else{
            if(i==k){
                for(int i=(int)v.size()-1;i>=0;i--)
                    cout << v[i];
                cout << endl;
                cout << i << endl;
            }
        }
    }
    return 0;
}