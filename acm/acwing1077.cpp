#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1510;

int e[maxn], ne[maxn], h[maxn], idx;
int n, val[maxn], st[maxn], f[maxn][3];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int u) {
  f[u][2] = val[u];
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i];
    dfs(v);
    f[u][0] += min(f[v][1], f[v][2]);
    f[u][2] += min(min(f[v][0], f[v][1]), f[v][2]);
  }
  f[u][1] = 1e9;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i];
    f[u][1] = min(f[u][1], f[v][2] + f[u][0] - min(f[v][1], f[v][2]));
  }
}

int main() {
  freopen("in1.txt", "r", stdin);
  memset(h, -1, sizeof h);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int id, k, m, r;
    cin >> id >> k >> m;
    val[id] = k;
    while (m--) {
      cin >> r;
      add(id, r);
      st[r] = 1;
    }
  }
  int root = 1;
  while (st[root])
    root++;
  dfs(root);
  cout << min(f[root][1], f[root][2]) << endl;
  return 0;
}
