#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int maxn = 60, inf = 0x3f3f3f3f;

vector<ll> f[maxn][maxn];
ll w[maxn];
int n;

vector<ll> add(vector<ll> &a, vector<ll> &b) {
  ll t = 0;
  vector<ll> ans;
  for (int i = 0; i < a.size() || i < b.size(); i++) {
    if (i < a.size())
      t += a[i];
    if (i < b.size())
      t += b[i];
    ans.push_back(t % 10);
    t /= 10;
  }
  if (t)
    ans.push_back(1);
  while (ans.size() > 1 && ans.back() == 0)
    ans.pop_back();
  return ans;
}

vector<ll> mul(vector<ll> &a, ll b) {
  ll t = 0;
  vector<ll> ans;
  for (int i = 0; i < a.size(); i++) {
    t += a[i] * b;
    ans.push_back(t % 10);
    t /= 10;
  }
  while (t)
    ans.push_back(t % 10), t /= 10;
  while (ans.size() > 1 && ans.back() == 0)
    ans.pop_back();
  return ans;
}

bool cmp(vector<ll> &a, vector<ll> &b) {
  if (a.size() < b.size())
    return true;
  else if (a.size() > b.size())
    return false;
  for (int i = a.size() - 1; i >= 0; i--)
    if (a[i] != b[i])
      return a[i] < b[i];
  return false;
}

void init_inf(vector<ll> &v) {
  for (int i = 0; i < 30; i++)
    v.push_back(9);
}

void print(vector<ll> &v) {
  while (v.size() > 1 && v.back() == 0)
    v.pop_back();
  for (int i = v.size() - 1; i >= 0; i--)
    cout << v[i];
  cout << endl;
}

int main() {
  freopen("in1.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  for (int len = 3; len <= n; len++)
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      init_inf(f[l][r]);
      for (int k = l + 1; k < r; k++) {
        vector<ll> res;
        res.push_back(1);
        res = mul(res, w[l]);
        res = mul(res, w[k]);
        res = mul(res, w[r]);
        res = add(res, f[l][k]);
        res = add(res, f[k][r]);
        if (cmp(res, f[l][r]))
          f[l][r] = res;
      }
    }
  print(f[1][n]);
  return 0;
}
