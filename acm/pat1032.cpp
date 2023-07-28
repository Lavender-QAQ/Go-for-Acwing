#include <iostream>
using namespace std;
const int maxn=1e6+10;

int h1,h2,ne[maxn],vis[maxn],n;
char e[maxn];

int main(){
    cin>>h1>>h2>>n;
    int a,b;
    char c;
    for(int i=0;i<n;i++){
        cin>>a>>c>>b;
        e[a]=c;
        ne[a]=b;
    }
    for(int i=h1;i!=-1;i=ne[i]) vis[i]=1;
    for(int i=h2;i!=-1;i=ne[i]){
        if(vis[i]==1){
            printf("%05d\n",i);
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}