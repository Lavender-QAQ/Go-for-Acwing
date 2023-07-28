#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

const int maxn = 1010;

int g[maxn][maxn], vis[maxn][maxn], peak, valley, n;
int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

void bfs(int x, int y) {
  bool is_peak = true, is_valley = true;
  queue<P> que;
  que.push(make_pair(x, y));
  vis[x][y] = 1;
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    int x = p.first, y = p.second;
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
        if (g[nx][ny] == g[x][y]) {
          if (!vis[nx][ny]) {
            que.push(make_pair(nx, ny));
            vis[nx][ny] = 1;
          }
        } else {
          if (g[nx][ny] > g[x][y])
            is_peak = false;
          else
            is_valley = false;
        }
      }
    }
  }
  if (is_peak)
    peak++;
  if (is_valley)
    valley++;
}

int main() {
  freopen("in1.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &g[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!vis[i][j]) {
        bfs(i, j);
      }
  printf("%d %d\n", peak, valley);
  return 0;
}
