#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e5+10;

int son[maxn][10],flag[maxn],tot,root;
char s[maxn][15];

void Trie(){
    memset(son[1],0,sizeof(son[1]));
    flag[1]=0;
    tot=root=1;
}

void insert(const char* str){
    int* cur=&root;
    for(const char* p=str;*p;p++){
        cur=&son[*cur][*p-'0'];
        if(!*cur){
            *cur=++tot;//创建新节点
            memset(son[tot],0,sizeof(son[tot]));
            flag[tot]=0;
        }
    }
    flag[*cur]++;
}

bool query(const char* str){
    int *cur=&root;
    for(const char* p=str;*p&&*cur;p++){
        cur=&son[*cur][*p-'0'];
        if(flag[*cur]>1||(flag[*cur]==1&&*(p+1)!='\0'))
            return false;
    }
    return true;
}

int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        Trie();
        scanf("%d",&n);
        int f=1;
        for(int i=0;i<n;i++)
            scanf("%s",s[i]),insert(s[i]);
        for(int i=0;i<n;i++){
            if(!query(s[i])){
                f=0;
                printf("NO\n");
                break;
            }
        }
        if(f)
            printf("YES\n");
    }
    return 0;
}