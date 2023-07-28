#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=20;

vector<int> va,vb;

int main(){
    string a;
    int b;
    cin>>a>>b;
    for(int i=0;i<a.length();i++){
        va.push_back(a[i]-'0');
    }
    sort(va.begin(),va.end());
    int k=0;
    while(k<va.size()&&va[k]==0) k++;
    bool ans=false;
    if(k==va.size()){
        if(b==0){
            ans=true;
        } else {
            ans=false;
        }
    } else {
        swap(va[0],va[k]);
        int sum=0;
        for(int i=0;i<va.size();i++){
            sum=sum*10+va[i];
        }
        if(sum==b){
            ans=true;
        } else {
            ans=false;
        }
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}