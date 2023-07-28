#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;
const int N = 362880;
int vis[N];
int par[N];
int dir[N];
//这里手动记下了1-9的阶乘，提高效率
const int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
struct Node {
    char s[9];
    int loc;
};

//康托展开编码函数
int encode(const char *a)
{
    int i,j,t,sum;
    sum=0;
    for( i=0; i<9 ;++i)
    {
        t=0;
        for(j=i+1;j<9;++j)
            if( a[i]>a[j] )
                ++t;
        sum+=t*fact[9-i-1];
    }
    return sum+1;
}

//康托展开解码函数
void decode(int k,Node& node) {
    int i, j, t, vst[10] = {0};
    --k;
    for (i = 0; i < 9; i++) {
        t = k / fact[9 - i - 1];
        for (j = 1; j <= 9; j++)
            if (!vst[j]) {
                if (t == 0) break;
                --t;
            }
        node.s[i] = j;
        vst[j] = 1;
        k %= fact[9 - i - 1];
    }
    for(int i=0;i<9;i++){
        if((int)node.s[i]==9){
            node.loc=i;
            break;
        }
    }
}
//搜索
void bfs(const Node& begin)
{
    memset(vis, 0, sizeof(vis));
    int code = encode(begin.s);
    vis[code] = 1;
    par[code] = -1;//保存了每一步的父节点,便于输出答案

    queue<int> que;//BFS标准配置，队列一个，放入康托展开后的编码
    que.push(code);

    Node n1, n2;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();

        decode(u, n1);

        int k = n1.loc;//loc记下空格所在的位置，方便日后换位
        int x = k/3;
        int y = k%3;

        for(int i=0; i<4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<3 && ny>=0 && ny<3)
            {
                n2 = n1;
                n2.loc = nx * 3 + ny;
                swap(n2.s[k], n2.s[n2.loc]);//进行换位你
                int v = encode(n2.s);//重新利用康托展开编码
                if(!vis[v])
                {
                    dir[v] = i;//保存方向
                    vis[v] = 1;//表示已经访问
                    par[v] = u;//记录父节点
                    if(v==1)
                        return;
                    que.push(v);
                }
            }
        }
    }
}

void output()
{
    int n, u;
    char path[1000];
    n = 1;
    path[0] = dir[1];
    u = par[1];
    while(par[u]!=-1)
    {
        path[n] = dir[u];
        ++n;
        u = par[u];
    }

    for(int i=n-1; i>=0; --i)
    {
        if(path[i]==0)
            cout << "u";
        else if(path[i]==1)
            cout << "d";
        else if(path[i]==2)
            cout << "l";
        else
            cout << "r";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Node start;
    char c;
    for(int i=0; i<9; ++i)
    {
        cin >> c;
        if(c=='x')
        {
            start.s[i] = 9;//当发现了x，将其变成9
            start.loc = i;
        }
        else
            start.s[i] = c - '0';
    }

    bfs(start);

    if(vis[1]==1)
        output();
    else
        cout << "unsolvable";

    cout << endl;
    return 0;
}