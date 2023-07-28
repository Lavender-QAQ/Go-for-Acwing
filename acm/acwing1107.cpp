#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

char g[2][4];

unordered_map<string, int> d;
unordered_map<string, pair<char, string>> pre;

void set(string &s) {
  for (int i = 0, j = 0; i < 4; i++, j++)
    g[0][j] = s[i];
  for (int i = 4, j = 3; i < 8; i++, j--)
    g[1][j] = s[i];
}

string get() {
  string s;
  for (int i = 0; i < 4; i++)
    s += g[0][i];
  for (int i = 3; i >= 0; i--)
    s += g[1][i];
  return s;
}

string moveA(string &s) {
  set(s);
  for (int i = 0; i < 4; i++)
    swap(g[0][i], g[1][i]);
  return get();
}

string moveB(string &s) {
  set(s);
  swap(g[0][0], g[0][3]), swap(g[1][0], g[1][3]);
  swap(g[0][1], g[0][2]), swap(g[1][1], g[1][2]);
  swap(g[0][1], g[0][3]), swap(g[1][1], g[1][3]);
  return get();
}

string moveC(string &s) {
  set(s);
  swap(g[0][1], g[0][2]);
  swap(g[0][1], g[1][2]);
  swap(g[0][1], g[1][1]);
  return get();
}

char op(int i) {
  if (i == 0)
    return 'A';
  else if (i == 1)
    return 'B';
  else
    return 'C';
}

int bfs(string &st, string &ed) {
  queue<string> que;
  que.push(st);
  d[st] = 0;
  while (!que.empty()) {
    string t = que.front();
    que.pop();
    if (t == ed)
      return d[ed];
    string nt[3];
    nt[0] = moveA(t);
    nt[1] = moveB(t);
    nt[2] = moveC(t);
    for (int i = 0; i < 3; i++) {
      if (!d.count(nt[i])) {
        d[nt[i]] = d[t] + 1;
        pre[nt[i]] = make_pair(op(i), t);
        que.push(nt[i]);
      }
    }
  }
  return -1;
}

int main() {
  freopen("in1.txt", "r", stdin);
  string st, ed;
  int x;
  for (int i = 0; i < 8; i++)
    cin >> x, ed += char(x + '0');
  for (int i = 1; i <= 8; i++)
    st += char(i + '0');
  int step = bfs(st, ed);
  cout << step << endl;
  if (step > 0) {
    string ans;
    while (ed != st) {
      ans += pre[ed].first;
      ed = pre[ed].second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
  return 0;
}