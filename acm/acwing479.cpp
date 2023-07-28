#include <iostream>
using namespace std;

const int maxn = 50;

int f[maxn][maxn], g[maxn][maxn], w[maxn], n;

void dfs(int l, int r) {
  if (l > r)
    return;
  int k = g[l][r];
  if (!k)
    return;
  else {
    cout << k << ' ';
    dfs(l, k - 1);
    dfs(k + 1, r);
  }
}

int main() {
  freopen("in1.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> w[i], f[i][i] = w[i],g[i][i]=i;
  for (int len = 2; len <= n; len++)
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      for (int k = l; k <= r; k++) {
        int left = k == l ? 1 : f[l][k - 1];
        int right = k == r ? 1 : f[k + 1][r];
        int score = left * right + w[k];
        if (score > f[l][r]) {
          f[l][r] = score;
          g[l][r] = k;
        }
      }
    }
  cout << f[1][n] << endl;
  dfs(1, n);
  cout << endl;
  return 0;
}
