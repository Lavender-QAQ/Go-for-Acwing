#include <stdio.h>
#include <string.h>

int p,n;
int line[500][500],vis[500],belong[500];

bool find(int x){
    for(int i=1;i<=n;i++){
        if(line[x][i]&&!vis[i]){
            vis[i]=1;
            if(!belong[i]||find(belong[i])){
                belong[i]=x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        memset(belong,0,sizeof(belong));
        memset(line,0,sizeof(line));
        scanf("%d%d",&p,&n);
        int c,in;
        for(int i=1;i<=p;i++){
            scanf("%d",&c);
            for(int j=1;j<=c;j++){
                scanf("%d",&in);
                line[in][i]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=p;i++){
            memset(vis,0,sizeof(vis));
            if(find(i))
                ans++;
        }
        if(ans==p)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
