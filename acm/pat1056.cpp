#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int,int> P;
const int maxn=100010;

vector<P> v;
int s[maxn];
priority_queue<P> que;

int main(){
    int n,m,x;
    queue<P> win,t;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>x,v.push_back({x,i});
    for(int i=0;i<n;i++)
        cin>>x,win.push(v[x]);
    while(win.size()>1){
        int group=(int)ceil((double)win.size()/m);
        //cout << group << endl;
        int grade=group+1;
        while(group--){
            for(int i=0;i<m&&!win.empty();i++){
                que.push(win.front());win.pop();
            }
            t.push(que.top());que.pop();
            while(!que.empty()){
                P p=que.top();que.pop();
                s[p.second]=grade;
            }
        }
        while(!t.empty()){
            win.push(t.front());t.pop();
        }
    }
    s[win.front().second]=1;
    for(int i=0;i<n;i++){
        if(i) cout << ' ';
        cout << s[i];
    }
    cout << endl;
    return 0;
}