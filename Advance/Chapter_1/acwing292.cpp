#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 15, M = 1 << 10;

int g[110], cnt[M], f[2][M][M];
vector<int> state;

bool check(int x) {
    return (x >> 1 & x) || (x >> 2 & x);
}

int count(int x) {
    int res = 0;
    while (x) {
        res += x & 1;
        x >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    char c;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        for (int j = 0;j < m;j++) {
            cin >> c;
            if (c == 'H') g[i] += 1 << j;
        }
    for (int i = 0;i < 1 << m;i++)
        if (!check(i)) {
            state.push_back(i);
            cnt[i] = count(i);
        }
    for (int i = 1;i <= n + 2;i++)
        for (int& c : state)
            for (int& b : state)
                for (int& a : state) {
                    if (a & b | a & c | b & c) continue;
                    if (g[i - 1] & b | g[i] & a) continue;
                    f[i & 1][a][b] = max(f[i & 1][a][b], f[i - 1 & 1][b][c] + cnt[a]);
                }
    cout << f[n + 2 & 1][0][0] << endl;
    return 0;
}