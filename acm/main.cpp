#include <iostream>
#include <queue>
#include <unordered_set>
#include <cmath>
using namespace std;

typedef pair<int,int> P;

const int N=2e5+10;
int a[N],b[N],low[N];


int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int zero=0,one=0;
    priority_queue<P> que;
    for(int i=n-1;i>=0;i--) {
        if(b[i]==2) low[i]=zero+one+1;
        else if(b[i]==1) low[i]=zero+1,one++;
        else zero++;
        que.push({low[i],i});
    }
    unordered_set<int> set;
    int ans=0;
    while(!que.empty()){
        P p=que.top();que.pop();
        int l=p.first,i=p.second,r=n;
        if(l<=a[i]&&a[i]<=r) {
            bool f=false;
            for(int k=a[i];k<=r;k++){
                if(!set.count(k)){
                    ans+=abs(k-a[i]);
                    set.insert(k);
                    f=true;
                    break;
                }
            }
            if(!f) {
                for (int k = a[i] - 1; k >= l; k--) {
                    if (!set.count(k)) {
                        ans += abs(k - a[i]);
                        set.insert(k);
                        f = true;
                        break;
                    }
                }
            }
        } else if(a[i]>r) {
            for(int k=r;k>=l;k--){
                if (!set.count(k)) {
                    ans += abs(k - a[i]);
                    set.insert(k);
                    break;
                }
            }
        } else {
            for(int k=l;k<=r;k++){
                if (!set.count(k)) {
                    ans += abs(k - a[i]);
                    set.insert(k);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
