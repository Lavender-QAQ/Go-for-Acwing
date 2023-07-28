#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 210;

int f[maxn][maxn], w[maxn], n;

int main() {
  freopen("in1.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> w[i], w[i + n] = w[i];
  for (int len = 3; len <= n+1; len++)
    for (int l = 1; l + len - 1 <= 2 * n; l++) {
      int r = l + len - 1;
      for (int k = l + 1; k < r; k++)
        f[l][r] = max(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]);
    }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = max(ans, f[i][i + n]);
  cout << ans << endl;
  return 0;
}