#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

const int maxn = 160;

char g[maxn][maxn];
int vis[maxn][maxn], d[maxn][maxn], n, m;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
P st, ed;

void bfs() {
  queue<P> que;
  que.push(st);
  vis[st.first][st.second] = 1;
  d[st.first][st.second] = 0;
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    int x = p.first, y = p.second;
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
          g[nx][ny] != '*') {
        d[nx][ny] = min(d[nx][ny], d[x][y] + 1);
        que.push(make_pair(nx, ny));
        vis[nx][ny] = 1;
      }
    }
  }
}

int main() {
  freopen("in1.txt", "r", stdin);
  memset(d, 0x3f, sizeof(d));
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", g[i]);
    for (int j = 0; j < m; j++)
      if (g[i][j] == 'K')
        st = make_pair(i, j);
      else if (g[i][j] == 'H')
        ed = make_pair(i, j);
  }
  bfs();
  printf("%d\n", d[ed.first][ed.second]);
  return 0;
}