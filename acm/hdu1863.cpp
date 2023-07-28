#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=200;

int f[maxn],r[maxn];
int n,m;

struct edge{
    int from,to,val;
}e[maxn];

bool cmp(edge a,edge b){
    return a.val<b.val;
}

void init(){//首先创建f数组与r数组
    for(int i=0;i<n;i++)
        f[i]=i;//每一个节点一开始都是离散的，所以直接用i赋值
    //对于r数组，由于每一个节点一开始的深度都是0，所以直接memset
    memset(r,0,sizeof(r));
}

int find(int x){
    //这句可能会有点难理解，find函数是我们使用并查集的核心
    //最简单的原理就是我们一直通过f数组去找到并查集集合内树的顶点
    //然后在return的时候顺便保存到f数组内方便下次查找
    return f[x]=f[x]==x?x:find(f[x]);
}

void merge(int a,int b){
    //merge没什么难的，就是对f数组的操作
    //唯一需要的注意点就是当两个树的高度一致时需要选择一个子树的rank+1（画图理解）
    int x=find(a);
    int y=find(b);
    if(r[x]<r[y])
        f[x]=y;
    else{
        f[y]=x;
        if(r[x]==r[y])
            r[x]++;
    }
}

bool same(int x,int y){
    //这个函数简易到不写都行
    return find(x)==find(y);
}

int main(){
    ios::sync_with_stdio(false);
    while(cin>>m>>n&&m){
        init();
        for(int i=0;i<m;i++) {
            cin >> e[i].from >> e[i].to >> e[i].val;
            e[i].from--;
            e[i].to--;
        }
        sort(e,e+m,cmp);
        int sum=0;
        for(int i=0;i<m;i++){
            if(same(e[i].from,e[i].to))
                continue;
            else{
                merge(e[i].from,e[i].to);
                sum+=e[i].val;
            }
        }
        int flag=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!same(i,j)){
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
            cout << sum << endl;
        else
            cout << '?' << endl;
    }
    return 0;
}