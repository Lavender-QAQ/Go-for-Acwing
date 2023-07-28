#include <iostream>
using namespace std;
const int maxn=1e5+10;

int s[maxn];

int main(){
    int n,m,x;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&x),s[x]++;
    bool flag=false;
    for(int i=0;i<=m/2;i++){
        if((i!=m-i&&s[i]&&s[m-i])||(i==m-i&&s[i]>1)){
            printf("%d %d\n",i,m-i);
            flag=true;
            break;
        }
    }
    if(!flag) puts("No Solution");
    return 0;
}