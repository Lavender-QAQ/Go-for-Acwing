#include <iostream>
using namespace std;

const int maxn = 1e5 + 10;

int n, m, a[maxn], b[maxn];

bool judge() {
  if (n > m)
    return false;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (a[i] == b[j])
      i++;
    j++;
  }
  return i == n;
}

int main() {
  freopen("in1.txt", "r", stdin);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  judge() ? puts("Yes") : puts("No");
  return 0;
}
