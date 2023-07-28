#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

const int maxn = 100;

int g[maxn][maxn], vis[maxn][maxn], n, m;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int bfs(int x, int y) {
  int res = 1;
  queue<P> que;
  vis[x][y] = 1;
  que.push(make_pair(x, y));
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    int x = p.first, y = p.second;
    for (int i = 0; i < 4; i++) {
      if ((g[x][y] >> i) & 1)
        continue;
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
        que.push(make_pair(nx, ny));
        vis[nx][ny] = 1;
        res++;
      }
    }
  }
  return res;
}

int main() {
  freopen("in1.txt", "r", stdin);
  scanf("%d%d,", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &g[i][j]);
  int cnt = 0, area = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!vis[i][j]) {
        area = max(area, bfs(i, j));
        cnt++;
      }
  printf("%d\n%d\n", cnt, area);
  return 0;
}
