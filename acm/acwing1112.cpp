#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 110;

int vis[maxn][maxn], stx, sty, edx, edy, n;
char g[maxn][maxn];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool dfs(int x, int y) {
  if (g[edx][edy] == '#' || g[stx][sty] == '#')
    return false;
  if (x == edx && y == edy)
    return true;
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] &&
        g[nx][ny] == '.') {
      if (dfs(nx, ny))
        return true;
    }
  }
  return false;
}

int main() {
  freopen("in1.txt", "r", stdin);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> g[i];
    cin >> stx >> sty >> edx >> edy;
    memset(vis, 0, sizeof vis);
    if (dfs(stx, sty))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
