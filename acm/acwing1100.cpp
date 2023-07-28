#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 2e5;

int d[maxn], vis[maxn];

int main() {
  freopen("in1.txt", "r", stdin);
  int n, k;
  cin >> n >> k;
  queue<int> que;
  memset(d, 0x3f, sizeof(d));
  que.push(n);
  vis[n] = 1;
  d[n] = 0;
  while (!que.empty()) {
    int pos = que.front();
    que.pop();
    if (pos == k)
      break;
    if (pos - 1 >= 0 && !vis[pos - 1]) {
      que.push(pos - 1);
      vis[pos - 1] = 1;
      d[pos - 1] = min(d[pos - 1], d[pos] + 1);
    }
    if (pos + 1 < maxn && !vis[pos + 1]) {
      que.push(pos + 1);
      vis[pos + 1] = 1;
      d[pos + 1] = min(d[pos + 1], d[pos] + 1);
    }
    if (pos * 2 < maxn && !vis[pos * 2]) {
      que.push(pos * 2);
      vis[pos * 2] = 1;
      d[pos * 2] = min(d[pos * 2], d[pos] + 1);
    }
  }
  cout << d[k] << endl;
  return 0;
}