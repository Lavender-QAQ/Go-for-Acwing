#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 110;

int h[maxn], e[maxn], ne[maxn], idx;
int v[maxn], w[maxn], n, m;
int f[maxn][maxn];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int u) {
  for (int i = h[u]; i != -1; i = ne[i]) {
    int son = e[i];
    dfs(son);

    for (int j = m - v[u]; j >= 0; j--)
      for (int k = 0; k <= j; k++)
        f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
  }
  for (int i = m; i >= v[u]; i--)
    f[u][i] = f[u][i - v[u]] + w[u];
  for (int i = 0; i < v[u]; i++)
    f[u][i] = 0;
}

int main() {
  freopen("in1.txt", "r", stdin);
  memset(h, -1, sizeof h);
  int p, root;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i] >> p;
    if (p == -1)
      root = i;
    else
      add(p, i);
  }
  dfs(root);
  cout << f[root][m] << endl;
  return 0;
}