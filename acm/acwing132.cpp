#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000010;

int mp[maxn],exist[1010];
int n,tot;
queue<int> q[1010];
queue<int> que;

int main(){
    ios::sync_with_stdio(false);
    tot=1;
    while(cin>>n&&n){
        cout << "Scenario #" << tot << endl;
        tot++;
        memset(mp,0,sizeof(mp));
        memset(exist,0,sizeof(exist));
        while(!que.empty()) que.pop();
        for(int i=0;i<1010;i++)
            while(!q[i].empty())
                q[i].pop();
        int cnt,t;
        string s;
        for(int i=1;i<=n;i++){
            cin>>cnt;
            while(cnt--){
                cin>>t;
                mp[t]=i;
            }
        }
        while(cin>>s&&s!="STOP"){
            if(s=="ENQUEUE"){
                cin>>t;
                q[mp[t]].push(t);
                if(exist[mp[t]]==0)
                    que.push(mp[t]),exist[mp[t]]=1;
            }
            else{
                int p=que.front();
                cout << q[p].front() << endl;
                q[p].pop();
                if(q[p].empty())
                    que.pop(),exist[p]=0;
            }
        }
        cout << endl;
    }
    return 0;
}

