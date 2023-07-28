#include <iostream>
#include <cstring>
using namespace std;

int s[110][110];
int w[110];
int l[110];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,h;
    while(cin>>n>>m>>h){
        memset(s,0,sizeof(s));
        memset(w,0,sizeof(w));
        memset(l,0,sizeof(l));
        for(int i=0;i<m;i++)
            cin>>w[i];
        for(int i=0;i<n;i++)
            cin>>l[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s[i][j]=w[j];
            }
        }
        for(int i=0;i<n;i++) {
            for (int j = 0; j < m; j++) {
                s[i][j] = min(s[i][j], l[i]);
            }
        }
        int in;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>in;
                s[i][j]=in==1?s[i][j]:0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if (j) cout << ' ';
                cout << s[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}