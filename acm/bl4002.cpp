#include <iostream>
#include <cstring>
using namespace std;
const int maxn=300;

int a[maxn],s[maxn];

int main(){
    int n,m;
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        for(int i=0;i<n;i++){
            cin>>a[i];
            s[a[i]]++;
        }
        for(int i=0;i<n;i++)
            if(s[a[i]]-1)
                cout << s[a[i]]-1 << endl;
            else
                cout << "BeiJu" << endl;
    }
    return 0;
}
