#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> P;

int change[4][4];

int get(int x,int y){
    return 4*x+y;
}

void init(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                change[i][j]+=1<<get(i,k);
                change[i][j]+=1<<get(k,j);
            }
            change[i][j]-=1<<get(i,j);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    string str;
    int state=0;
    for(int i=0;i<4;i++){
        cin>>str;
        for(int j=0;j<4;j++){
            if(str[j]=='+')
                state+=1<<get(i,j);
        }
    }
    init();
    vector<P> v,ans;
    for(int n=0;n<(1<<16);n++){
        int s=state;
        v.clear();
        for(int i=0;i<16;i++){
            if(n>>i&1){
                int x=i/4,y=i%4;
                s^=change[x][y];
                v.emplace_back(make_pair(x+1,y+1));
            }
        }
        if(s==0&&(ans.empty()||v.size()<ans.size()))
            ans=v;
    }
    cout << ans.size() << endl;
    for(auto i:ans)
        cout << i.first << ' ' << i.second << endl;
    return 0;
}

