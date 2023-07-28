#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=1010;

int main(){
    string s;
    int a[maxn];
    vector<int> ans;
    while(cin>>s){
        ans.clear();
        memset(a,0,sizeof(a));
        int sum=0,flag=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='5') {
                if(flag)
                    ans.push_back(sum);
                sum = 0;
                flag=0;
            }
            else {
                flag=1;
                sum *= 10;
                sum += s[i] - '0';
            }
            if(i==s.length()-1&&s[i]!='5')
                ans.push_back(sum);
        }
        sort(ans.begin(),ans.end());
        for(auto it=ans.begin();it!=ans.end();it++){
            if(it!=ans.begin()) cout << ' ';
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}