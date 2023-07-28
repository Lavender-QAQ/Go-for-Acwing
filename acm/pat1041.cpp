#include <iostream>
#include <vector>
using namespace std;
const int maxn=1e5+10;

int s[maxn];

int main(){
    int n,x;
    vector<int> v;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        v.push_back(x);
        s[x]++;
    }
    bool flag=false;
    for(auto i:v){
        if(s[i]==1){
            printf("%d\n",i);
            flag=true;
            break;
        }
    }
    if(!flag) puts("None");
    return 0;
}