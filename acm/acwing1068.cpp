#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 210 * 2, inf = 0x3f3f3f3f;

int f_mx[maxn][maxn], f_mi[maxn][maxn], s[maxn], a[maxn], n;

int main() {
  freopen("in1.txt", "r", stdin);
  memset(f_mi, inf, sizeof f_mi);
  memset(f_mx, -inf, sizeof f_mx);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i], a[i + n] = a[i];
  for (int i = 1; i <= 2 * n; i++)
    s[i] += s[i - 1] + a[i], f_mx[i][i] = f_mi[i][i] = 0;
  for (int len = 2; len <= n; len++)
    for (int i = 1; i + len - 1 <= 2 * n; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++) {
        f_mx[i][j] =
            max(f_mx[i][j], f_mx[i][k] + f_mx[k + 1][j] + s[j] - s[i - 1]);
        f_mi[i][j] =
            min(f_mi[i][j], f_mi[i][k] + f_mi[k + 1][j] + s[j] - s[i - 1]);
      }
    }
  int mx = INT_MIN, mi = INT_MAX;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, f_mx[i][i + n - 1]);
    mi = min(mi, f_mi[i][i + n - 1]);
  }
  cout << mi << endl << mx << endl;
  return 0;
}
