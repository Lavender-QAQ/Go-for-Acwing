#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1510;

int e[maxn], ne[maxn], h[maxn], idx;
int f[maxn][2], flag[maxn], n;

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int u) {
  f[u][1] = 1;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i];
    dfs(v);
    f[u][0] += f[v][1];
    f[u][1] += min(f[v][0], f[v][1]);
  }
}

int main() {
  freopen("in1.txt", "r", stdin);
  while (~scanf("%d", &n)) {
    memset(h, -1, sizeof h);
    memset(flag, 0, sizeof flag);
    memset(f, 0, sizeof f);
    idx = 0;
    while (n--) {
      int a, b, cnt;
      scanf("%d:(%d)", &a, &cnt);
      while (cnt--) {
        scanf("%d", &b);
        add(a, b);
        flag[b] = 1;
      }
    }
    int root = 0;
    while (flag[root])
      root++;
    dfs(root);
    printf("%d\n", min(f[root][0], f[root][1]));
  }
  return 0;
}
