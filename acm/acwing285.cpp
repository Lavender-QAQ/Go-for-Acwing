#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 6010;

int e[maxn], ne[maxn], h[maxn], idx;
int f[maxn][2], has_father[maxn], happy[maxn], n;

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int u) {
  f[u][1] = happy[u];
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i];
    dfs(v);
    f[u][0] += max(f[v][0], f[v][1]);
    f[u][1] += f[v][0];
  }
}

int main() {
  freopen("in1.txt", "r", stdin);
  memset(h, -1, sizeof h);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> happy[i];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    add(b, a);
    has_father[a] = 1;
  }
  int root = 1;
  while (has_father[root])
    root++;
  dfs(root);
  cout << max(f[root][0], f[root][1]) << endl;
}