#include <cstring>
#include <deque>
#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 2e6 + 10;

ll a[maxn], s[maxn], ans[maxn], p[maxn], d[maxn], n;

void solve1() {
  deque<ll> que;
  for (int pos = 2 * n; pos; pos--) {
    while (que.size() && s[pos] <= s[que.back()])
      que.pop_back();
    que.push_back(pos);
    if (pos <= n) {
      if (que.size() && que.front() - pos + 1 > n)
        que.pop_front();
      if (que.size() && s[que.front()] - s[pos - 1] >= 0)
        ans[pos] = 1;
    }
  }
}

void solve2() {
  deque<ll> que;
  for (int pos = 1; pos <= 2 * n; pos++) {
    while (que.size() && s[pos] <= s[que.back()])
      que.pop_back();
    que.push_back(pos);
    if (pos > n) {
      if (que.size() && pos - que.front() + 1 > n)
        que.pop_front();
      if (que.size() && s[que.front()] - s[pos + 1] >= 0)
        ans[pos - n] = 1;
    }
  }
}

int main() {
  freopen("in1.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> p[i] >> d[i], a[i + n] = a[i] = p[i] - d[i];
  for (int i = 1; i <= 2 * n; i++)
    s[i] = s[i - 1] + a[i];
  solve1();
  memset(s, 0, sizeof(s));
  for (int i = n; i >= 1; i--)
    a[i] = a[i + n] = p[i] - d[i - 1 == 0 ? n : i - 1];
  for (int i = n * 2; i >= 1; i--)
    s[i] += s[i + 1] + a[i];
  solve2();
  for (int i = 1; i <= n; i++) {
    if (ans[i])
      puts("TAK");
    else
      puts("NIE");
  }
  return 0;
}
