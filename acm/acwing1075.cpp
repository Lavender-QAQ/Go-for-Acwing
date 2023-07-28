#include <cstring>
#include <iostream>
using namespace std;

const int N = 50010;

int h[N], e[N], ne[N], idx, n, ans;
int sum[N];
bool node[N];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

int dfs(int u) {
  int d1 = 0, d2 = 0;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i];
    int d = dfs(v) + 1;
    if (d >= d1)
      d2 = d1, d1 = d;
    else if (d > d2)
      d2 = d;
  }
  ans = max(ans, d1 + d2);
  return d1;
}

int main() {
  memset(h, -1, sizeof h);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= n / i; j++)
      sum[i * j] += i;
  for (int i = 2; i <= n; i++)
    if (i > sum[i]) {
      add(sum[i],i);
      node[i] = true;
    }
  for (int i = 1; i <= n; i++)
    if(!node[i])
      dfs(i);
  cout << ans << endl;
  return 0;
}
