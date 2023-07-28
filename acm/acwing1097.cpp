#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

const int maxn = 1010;

char g[maxn][maxn];
int vis[maxn][maxn], ans, n, m;
int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

void bfs(int x, int y) {
  queue<P> que;
  que.push(make_pair(x, y));
  vis[x][y] = 1;
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    int x = p.first, y = p.second;
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
          g[nx][ny] == 'W') {
        que.push(make_pair(nx, ny));
        vis[nx][ny] = 1;
      }
    }
  }
}

int main() {
  freopen("in1.txt", "r", stdin);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%s", g[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (!vis[i][j] && g[i][j] == 'W') {
        bfs(i, j);
        ans++;
      }
    }
  printf("%d\n", ans);
  return 0;
}
