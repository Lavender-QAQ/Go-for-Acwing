#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

const int maxn = 10;

string a[maxn], b[maxn], sa, sb;
int n;

int extend(queue<string> &que, unordered_map<string, int> &mpa,
           unordered_map<string, int> &mpb, string a[], string b[]) {
  string s = que.front();
  que.pop();
  for (int i = 0; i < s.size(); i++)
    for (int j = 0; j < n; j++)
      if (s.substr(i, a[j].size()) == a[j]) {
        string ns = s.substr(0, i) + b[j] + s.substr(i + a[j].size());
        if (mpa.count(ns))
          continue;
        mpa[ns] = mpa[s] + 1;
        if (mpb.count(ns))
          return mpa[ns] + mpb[ns];
        que.push(ns);
      }
  return 11;
}

int bfs() {
  if (sa == sb)
    return 0;
  queue<string> qa, qb;
  unordered_map<string, int> mpa, mpb;
  qa.push(sa);
  qb.push(sb);
  mpa[sa] = 0;
  mpb[sb] = 0;
  while (!qa.empty() && !qb.empty()) {
    int ans;
    if (qa.size() <= qb.size())
      ans = extend(qa, mpa, mpb, a, b);
    else
      ans = extend(qb, mpb, mpa, b, a);
    if (ans <= 10)
      return ans;
  }
  return 11;
}

int main() {
  freopen("in1.txt", "r", stdin);
  cin >> sa >> sb;
  while (cin >> a[n] >> b[n])
    n++;
  int ans = bfs();
  if (ans > 10)
    puts("NO ANSWER!");
  else
    printf("%d\n", ans);
  return 0;
}
