#include <deque>
#include <iostream>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

ll f[maxn], s[maxn];

ll g(int i) { return f[i - 1] - s[i]; }

int main() {
  freopen("in1.txt", "r", stdin);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> s[i], s[i] += s[i - 1];
  deque<ll> que;
  que.push_back(0);
  for (int i = 1; i <= n; i++) {
    while (que.size() && i - que.front() > k)
      que.pop_front();
    f[i] = max(f[i - 1], g(que.front()) + s[i]);
    while (que.size() && g(que.back()) <= g(i))
      que.pop_back();
    que.push_back(i);
  }
  cout << f[n] << endl;
  return 0;
}
