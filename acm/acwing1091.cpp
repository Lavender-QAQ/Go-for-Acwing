#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
using namespace std;

const int maxn = 1010;

int g[maxn][maxn], raw_min[maxn][maxn], col_min[maxn][maxn],
    raw_max[maxn][maxn], col_max[maxn][maxn];

int main() {
  freopen("in1.txt", "r", stdin);
  int a, b, n;
  scanf("%d%d%d", &a, &b, &n);
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      scanf("%d", &g[i][j]);
  deque<int> que_min, que_max;
  for (int i = 1; i <= a; i++) {
    que_min.clear();
    que_max.clear();
    for (int j = 1; j <= b; j++) {
      while (que_min.size() && g[i][que_min.back()] >= g[i][j])
        que_min.pop_back();
      while (que_max.size() && g[i][que_max.back()] <= g[i][j])
        que_max.pop_back();
      que_min.push_back(j);
      que_max.push_back(j);
      if (j >= n) {
        while (que_min.size() && j - que_min.front() + 1 > n)
          que_min.pop_front();
        while (que_max.size() && j - que_max.front() + 1 > n)
          que_max.pop_front();
      }
      raw_min[i][j] = g[i][que_min.front()];
      raw_max[i][j] = g[i][que_max.front()];
    }
  }
  for (int j = 1; j <= b; j++) {
    que_min.clear();
    que_max.clear();
    for (int i = 1; i <= a; i++) {
      while (que_min.size() && raw_min[que_min.back()][j] >= raw_min[i][j])
        que_min.pop_back();
      while (que_max.size() && raw_max[que_max.back()][j] <= raw_max[i][j])
        que_max.pop_back();
      que_min.push_back(i);
      que_max.push_back(i);
      if (i >= n) {
        while (que_min.size() && i - que_min.front() + 1 > n)
          que_min.pop_front();
        while (que_max.size() && i - que_max.front() + 1 > n)
          que_max.pop_front();
        col_min[i][j] = raw_min[que_min.front()][j];
        col_max[i][j] = raw_max[que_max.front()][j];
      }
    }
  }
  int ans = INT_MAX;
  for (int i = n; i <= a; i++)
    for (int j = n; j <= b; j++)
      ans = min(ans, col_max[i][j] - col_min[i][j]);
  printf("%d\n", ans);
  return 0;
}