#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> P;

const int maxn = 1010;

char g[maxn][maxn];
int vis[maxn][maxn], d[maxn][maxn], n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs() {
  queue<P> que;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == '1') {
        que.push(make_pair(i, j));
        vis[i][j] = 1;
        d[i][j] = 0;
      }
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    int x = p.first, y = p.second;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
        d[nx][ny] = d[x][y] + 1;
        vis[nx][ny] = 1;
        que.push(make_pair(nx, ny));
      }
    }
  }
}

int main() {
  freopen("in1.txt", "r", stdin);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%s", g[i]);
  bfs();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j)
        printf(" ");
      printf("%d", d[i][j]);
    }
    puts("");
  }
  return 0;
}
