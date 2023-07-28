#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  freopen("in1.txt", "r", stdin);
  int n, k, x;
  cin >> n >> k;
  vector<int> a, ans_max, ans_min;
  deque<int> v_min, v_max;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  int pos = 0;
  while (pos < k - 1) {
    while (v_min.size() && a[pos] <= a[v_min.back()])
      v_min.pop_back();
    while (v_max.size() && a[pos] >= a[v_max.back()])
      v_max.pop_back();
    v_min.push_back(pos);
    v_max.push_back(pos);
    pos++;
  }
  while (pos < n) {
    while (v_min.size() && a[pos] <= a[v_min.back()])
      v_min.pop_back();
    while (v_max.size() && a[pos] >= a[v_max.back()])
      v_max.pop_back();
    if (v_min.size() && pos - v_min.front() + 1 > k)
      v_min.pop_front();
    if (v_max.size() && pos - v_max.front() + 1 > k)
      v_max.pop_front();
    v_min.push_back(pos);
    v_max.push_back(pos);
    ans_min.push_back(a[v_min.front()]);
    ans_max.push_back(a[v_max.front()]);
    pos++;
  }
  for (int i = 0; i < ans_min.size(); i++) {
    if (i)
      cout << ' ';
    cout << ans_min[i];
  }
  cout << endl;
  for (int i = 0; i < ans_max.size(); i++) {
    if (i)
      cout << ' ';
    cout << ans_max[i];
  }
  cout << endl;
  return 0;
}
