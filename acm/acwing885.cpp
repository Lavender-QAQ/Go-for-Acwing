#include <cstdio>
using namespace std;

const int maxn = 2010;

int c[maxn][maxn];

void init() {
  for (int i = 0; i < maxn; i++)
    for (int j = 0; j <= i; j++) {
      if (!j)
        c[i][j] = 1;
      else
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
}

int main() {
  freopen("in1.txt", "r", stdin);
  init();
  int n;
  scanf("%d", &n);
  int a, b;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    printf("%d\n", c[a][b]);
  }
  return 0;
}
