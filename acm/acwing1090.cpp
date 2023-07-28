#include <cstring>
#include <deque>
#include <iostream>
using namespace std;

const int maxn = 5e4 + 10;

int n, t, a[maxn], f[maxn];

bool check(int limit) {
  memset(f, 0, sizeof(f));
  deque<int> que;
  que.push_back(0);
  for (int i = 1; i <= n; i++) {
    while (que.size() && i - que.front() - 1 > limit)
      que.pop_front();
    f[i] = f[que.front()] + a[i];
    while (que.size() && f[i] <= f[que.back()])
      que.pop_back();
    que.push_back(i);
  }
  for (int i = n - limit; i <= n; i++) {
    if (f[i] <= t)
      return true;
  }
  return false;
}

int main() {
  freopen("in1.txt", "r", stdin);
  cin >> n >> t;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
  return 0;
}
