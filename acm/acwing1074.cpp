#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 110 * 2;

int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int apple[maxn], f[maxn][maxn], n, m;

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void init(int u, int father) {
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i];
    if (v == father)
      continue;
    init(v, u);
    apple[v] = w[i];
  }
}

void dfs(int u, int father) {
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i];
    if (v == father)
      continue;
    dfs(v, u);
    for (int j = m - 1; j >= 0; j--)
      for (int k = 0; k <= j; k++)
        f[u][j] = max(f[u][j], f[u][j - k] + f[v][k]);
  }
  for (int i = m; i >= 1; i--)
    f[u][i] = f[u][i - 1] + apple[u];
  f[u][0] = 0;
}

int main() {
  freopen("in1.txt", "r", stdin);
  memset(h, -1, sizeof h);
  cin >> n >> m;
  m++;
  int a, b, c;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    add(a, b, c), add(b, a, c);
  }
  init(1, -1);
  dfs(1, -1);
  cout << f[1][m] << endl;
}
