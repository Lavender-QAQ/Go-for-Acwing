#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
using namespace std;

typedef pair<int, int> P;

const int maxn = 510;

char g[maxn][maxn], ig[] = "\\//\\";
int d[maxn][maxn], vis[maxn][maxn], n, m;
int dx[4] = {-1, -1, 1, 1}, ix[4] = {-1, -1, 0, 0};
int dy[4] = {-1, 1, -1, 1}, iy[4] = {-1, 0, -1, 0};

int bfs() {
  memset(d, 0x3f, sizeof(d));
  memset(vis, 0, sizeof(vis));
  deque<P> que;
  que.push_back(make_pair(0, 0));
  d[0][0] = 0;
  while (!que.empty()) {
    P p = que.front();
    que.pop_front();
    int x = p.first, y = p.second;
    if (vis[x][y])
      continue;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
        int dist = d[x][y] + (ig[i] != g[x + ix[i]][y + iy[i]]);
        if (d[nx][ny] > dist) {
          d[nx][ny] = dist;
          if (ig[i] != g[x + ix[i]][y + iy[i]])
            que.push_back(make_pair(nx, ny));
          else
            que.push_front(make_pair(nx, ny));
        }
      }
    }
  }
  return d[n][m];
}

int main() {
  freopen("in1.txt", "r", stdin);
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%s", g[i]);
    if ((n + m) & 1)
      puts("NO SOLUTION");
    else {
      printf("%d\n", bfs());
    }
  }
  return 0;
}
