#include <climits>
#include <deque>
#include <iostream>
using namespace std;

const int maxn = 2e5 + 10;

int w[maxn], f[maxn];

int main() {
  freopen("in2.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
  deque<int> que;
  que.push_back(0);
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  for (int i = 1; i <= n; i++) {
    while (que.size() && que.front() < i - m )
      que.pop_front();
    f[i] = f[que.front()] + w[i];
    while (que.size() && f[que.back()] >= f[i])
      que.pop_back();
    que.push_back(i);
  }
  int ans = INT_MAX;
  for (int i = n - m + 1 ; i <= n; i++)
    ans = min(ans, f[i]);
  cout << ans << endl;
  return 0;
}
