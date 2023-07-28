#include <climits>
#include <deque>
#include <iostream>
using namespace std;

const int maxn = 3e5 + 10;

int a[maxn], s[maxn];

int main() {
  freopen("in1.txt", "r", stdin);
  int n, m, ans = INT_MIN;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i], s[i] += s[i - 1] + a[i], ans = max(ans, a[i]);
  deque<int> que;
  for (int pos = 0; pos <= n; pos++) {
    if (que.size())
      ans = max(ans, s[pos] - s[que.front()]);
    while (que.size() && s[pos] <= s[que.back()])
      que.pop_back();
    while (que.size() && pos - que.front() + 1 > m)
      que.pop_front();
    que.push_back(pos);
  }
  cout << ans << endl;
  return 0;
}
