#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const int maxn=100010;

int n,l[maxn],r[maxn];
ll h[maxn];
stack<P> s;

int main(){
    while(cin>>n&&n){
        while(!s.empty()) s.pop();
        for(int i=0;i<n;i++){
            cin>>h[i];
            while(!s.empty()&&s.top().first>=h[i])
                s.pop();
            if(!s.empty())
                l[i]=s.top().second;
            else
                l[i]=-1;
            s.push({h[i],i});
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&s.top().first>=h[i])
                s.pop();
            if(!s.empty())
                r[i]=s.top().second;
            else
                r[i]=n;
            s.push({h[i],i});
        }
        ll mx=-1;
        for(int i=0;i<n;i++)
            mx=max(mx,(r[i]-l[i]-1)*h[i]);
        cout << mx << endl;
    }
    return 0;
}
