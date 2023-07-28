#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=50050;

struct cow{
    int x,y,id;
    bool operator< (const cow &a) const{
        return y>a.y;
    }
}cows[maxn];

bool cmp(cow& a,cow& b){
    return a.x<b.x;
}

int id[maxn];

int main(){
    ios::sync_with_stdio(false);
    int n;
    priority_queue<cow> que;
    while(cin>>n){
        while(!que.empty()) que.pop();
        memset(cows,0,sizeof(cows));
        memset(id,0,sizeof(id));
        for(int i=0;i<n;i++)
            cin>>cows[i].x>>cows[i].y,cows[i].id=i;
        sort(cows,cows+n,cmp);
        for(int i=0;i<n;i++){
            if(que.empty()||que.top().y>=cows[i].x){
                id[cows[i].id]=(int)que.size()+1;
                que.push(cows[i]);
            }
            else if(que.top().y<cows[i].x){
                id[cows[i].id]=id[que.top().id];
                cow t=que.top();que.pop();
                t.y=cows[i].y;
                que.push(t);
            }
        }
        cout << que.size() << endl;
        for(int i=0;i<n;i++)
            cout << id[i] << endl;
    }
    return 0;
}
