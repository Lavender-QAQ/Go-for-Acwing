#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 10010, M = 2 * N, inf = 0x3f3f3f3f;

int n, e[M], w[M], ne[M], h[N], idx;
int d1[N], d2[N], up[N], p1[N];

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs_d(int u, int father) {
  d1[u] = d2[u] = -inf;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i];
    if (v == father)
      continue;
    int d = dfs_d(v, u) + w[i];
    if (d >= d1[u])
      d2[u] = d1[u], d1[u] = d, p1[u] = v;
    else if (d > d2[u])
      d2[u] = d;
  }
  if (d1[u] == -inf)
    d1[u] = d2[u] = 0;
  return d1[u];
}

void dfs_u(int u, int father) {
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i];
    if (v == father)
      continue;
    if (p1[u] != v)
      up[v] = max(up[u], d1[u]) + w[i];
    else
      up[v] = max(up[u], d2[u]) + w[i];
    dfs_u(v, u);
  }
}

int main() {
  freopen("in1.txt", "r", stdin);
  int n;
  memset(h, -1, sizeof h);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c), add(b, a, c);
  }
  dfs_d(1, -1);
  dfs_u(1, -1);
  int ans = inf;
  for (int i = 1; i <= n; i++)
    ans = min(ans, max(d1[i], up[i]));
  cout << ans << endl;
  return 0;
}
