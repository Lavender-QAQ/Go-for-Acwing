#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

int convert(char c){
    if(c>='0'&&c<='9')
        return c-'0';
    if(c>='a'&&c<='z')
        return c-'a'+10;
}

ll cal(string& s,int d){
    ll ans=0;
    for(int i=0;i<s.length();i++)
        ans=ans*d+convert(s[i]);
    return ans;
}

int main(){
    string s1,s2;
    int tag,radix;
    ll s;
    int ans=-1;
    cin>>s1>>s2>>tag>>radix;
    if(tag==2) swap(s1,s2);
    s=cal(s1,radix);
    int k=0;
    for(auto c:s2)  k=max(k,convert(c));
    for(int i=k+1;;i++){
        ll res=cal(s2,i);
        if(s==res){
            ans=i;
            break;
        }
        else if(s<res) break;
    }
    if(ans==-1) puts("Impossible");
    else printf("%d\n",ans);
    return 0;
}
