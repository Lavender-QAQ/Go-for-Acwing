#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

typedef pair<int, string> P;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char op[] = "udlr";

int f(string s) {
  int ans = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] != 'x') {
      int t = s[i] - '1';
      ans += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
    }
  return ans;
}

string bfs(string &st) {
  string ed = "12345678x";
  unordered_map<string, int> d;
  priority_queue<P, vector<P>, greater<P>> que;
  unordered_map<string, pair<char, string>> pre;
  que.push(make_pair(f(st), st));
  d[st] = 0;
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int dist = p.first;
    string s = p.second;
    if (s == ed)
      break;
    int x, y, step = d[s];
    for (int i = 0; i < s.size(); i++)
      if (s[i] == 'x') {
        x = i / 3, y = i % 3;
        break;
      }
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
        swap(s[x * 3 + y], s[nx * 3 + ny]);
        if (!d.count(s) || d[s] > step + 1) {
          d[s] = step + 1;
          pre[s] = make_pair(op[i], p.second);
          que.push(make_pair(f(s) + d[s], s));
        }
        swap(s[x * 3 + y], s[nx * 3 + ny]);
      }
    }
  }
  string ans;
  while (ed != st) {
    ans += pre[ed].first;
    ed = pre[ed].second;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  freopen("in1.txt", "r", stdin);
  char c;
  string st, seq;
  for (int i = 0; i < 9; i++) {
    cin >> c;
    if (c != 'x')
      seq += c;
    st += c;
  }
  int cnt = 0;
  for (int i = 0; i < 8; i++)
    for (int j = i + 1; j < 8; j++)
      if (seq[i] > seq[j])
        cnt++;
  if (cnt & 1)
    puts("unsolvable");
  else
    cout << bfs(st) << endl;
  return 0;
}