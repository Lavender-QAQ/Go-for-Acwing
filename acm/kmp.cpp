#include <iostream>
using namespace std;
const int M=1e5+10,N=1e4+10;

int n,m;
char p[N],s[M];
int ne[N];

void pre_kmp(){
    ne[0]=-1,ne[1]=0;
    int i=1,j=0;
    while(i<n){
        while(p[i]!=p[j]) j=ne[j];
        i++,j++;
        ne[i]=j;
    }
}

void kmp(){
    for(int i=0,j=0;i<m;i++,j++){
        while(j>-1&&s[i]!=p[j]) j=ne[j];
        if(j==n-1){
            printf("%d ",i-n+1);
            j=ne[j];
        }
    }
    puts("");
}

int main(){
    scanf("%d%s%d%s",&n,p,&m,s);
    pre_kmp();
    kmp();
    return 0;
}