#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int get(vector<int> &v, int l, int r) {
  int ans = 0;
  for (int i = l; i >= r; i--) {
    ans = ans * 10 + v[i];
  }
  return ans;
}

int count(int n, int x) {
  if (!n)
    return 0;
  vector<int> v;
  while (n) {
    v.push_back(n % 10);
    n /= 10;
  }
  n = v.size();
  int ans = 0;
  for (int i = n - 1 - !x; i >= 0; i--) {
    if (i < n - 1) {
      ans += get(v, n - 1, i + 1) * pow(10, i);
      if (!x)
        ans -= pow(10, i);
    }
    if (v[i] == x)
      ans += get(v, i - 1, 0) + 1;
    else if (v[i] > x)
      ans += pow(10, i);
  }
  return ans;
}

int main() {
  freopen("in1.txt", "r", stdin);
  int a, b;
  while (cin >> a >> b, a || b) {
    if (a > b)
      swap(a, b);
    for (int i = 0; i < 10; i++)
      cout << count(b, i) - count(a - 1, i) << ' ';
    cout << endl;
  }
  return 0;
}