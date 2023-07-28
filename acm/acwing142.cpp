#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=(int)1e6+10;

int tot,root,trie[maxn][26];
int flag[maxn];
char s[maxn];

void Trie(){
    memset(trie[1],0,sizeof(trie[1]));
    flag[1]=1;
    root=tot=1;
}

void insert(const char *str){
    int *cur=&root;
    for(const char* p=str;*p;p++){
        cur=&trie[*cur][*p-'a'];
        if(*cur==0){
            *cur=++tot;
            memset(trie[tot],0,sizeof(trie[tot]));
            flag[tot]=0;
        }
    }
    flag[*cur]++;
}

int query(const char* str){
    int ans=0;
    int *cur=&root;
    for(const char *p=str;*p&&*cur;p++) {
        cur = &trie[*cur][*p - 'a'];
        if(!*cur)
            return ans;
        ans+=flag[*cur];
    }
    return ans;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    Trie();
    while(n--){
        scanf("%s",s);
        insert(s);
    }
    while(m--){
        scanf("%s",s);
        printf("%d\n",query(s));
    }
    return 0;
}

