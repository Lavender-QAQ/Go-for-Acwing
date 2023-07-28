#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int T,a,b;
    string A,B;
    cin>>T;
    while(T--){
        cin>>a>>b>>A;
        vector<int> v,ans;
        for(int i=(int)A.length()-1;i>=0;i--){
            if(A[i]>='0'&&A[i]<='9') v.push_back(A[i]-'0');
            else if(A[i]>='A'&&A[i]<='Z') v.push_back(A[i]-'A'+10);
            else if(A[i]>='a'&&A[i]<='z') v.push_back(A[i]-'a'+36);
        }
        while(!v.empty()){
            int r=0;
            for(int i=(int)v.size()-1;i>=0;i--){
                v[i]+=r*a;
                r=v[i]%b;
                v[i]/=b;
            }
            ans.push_back(r);
            while(!v.empty()&&v.back()==0) v.pop_back();
        }
        reverse(ans.begin(),ans.end());
        for(auto x:ans){
            if(x>=0&&x<=9) B+=char(x+'0');
            else if(x>=10&&x<=35) B+=char(x-10+'A');
            else if(x>=36) B+=char(x-36+'a');
        }
        cout << a << ' ' << A << endl;
        cout << b << ' ' << B << endl;
        cout << endl;
    }
    return 0;
}
