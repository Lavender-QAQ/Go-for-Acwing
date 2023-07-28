#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> P;


char ch[10][10];
int map[10][10];
vector<P> v;
int ans;

void reverse(P p){
    map[p.first][p.second]=!map[p.first][p.second];
    if(p.first-1>=0)
        map[p.first-1][p.second]=!map[p.first-1][p.second];
    if(p.first+1<4)
        map[p.first+1][p.second]=!map[p.first+1][p.second];
    if(p.second-1>=0)
        map[p.first][p.second-1]=!map[p.first][p.second-1];
    if(p.second+1<4)
        map[p.first][p.second+1]=!map[p.first][p.second+1];
}

bool judge(){
    int flag=map[0][0];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(flag!=map[i][j])
                return false;
        }
    }
    return true;
}

void dfs(int k,int count){
    if(judge()){
        if(ans>count)
            ans=count;
        return;
    }
    if(k>=15)
        return;
    P p=v[k+1];
    dfs(k+1,count);
    reverse(p);
    dfs(k+1,count+1);
    reverse(p);
}

int main(){
    ios::sync_with_stdio(false);
    v.clear();
    ans=(int)1e9;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>ch[i][j];
            map[i][j]=ch[i][j]=='b'?0:1;
            v.push_back(make_pair(i,j));
        }
    }
    dfs(-1,0);
    if(ans==(int)1e9)
        cout << "Impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}