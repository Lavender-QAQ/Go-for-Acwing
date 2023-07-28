#include <iostream>
using namespace std;

const int maxn = 1010;

int s[maxn][maxn], n, m, q;

int get(int x1, int y1, int x2, int y2) {
  return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

int main() {
  freopen("in1.txt", "r", stdin);
  int x1, y1, x2, y2;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
  while (q--) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << get(x1, y1, x2, y2) << endl;
  }
  return 0;
}
