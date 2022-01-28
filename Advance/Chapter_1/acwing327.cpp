#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 14, M = 1 << 13, mod = 1e8;

int g[N], f[N][M];
vector<int> state;
vector<int> h[M];

bool check(int x) {
    return x >> 1 & x;
}

int main() {
    int n, m, x;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        for (int j = 0;j < m;j++) {
            cin >> x;
            g[i] = (g[i] << 1) + !x;
        }
    for (int i = 0;i < 1 << m;i++)
        if (!check(i))
            state.push_back(i);
    for (int& a : state)
        for (int& b : state)
            if (!(a & b))
                h[a].push_back(b);
    f[0][0] = 1;
    for (int i = 1;i <= n + 1;i++)
        for (int& a : state) {
            if (g[i] & a) continue;
            for (int& b : h[a]) {
                if (g[i - 1] & b) continue;
                f[i][a] = (f[i][a] + f[i - 1][b]) % mod;
            }
        }
    cout << f[n + 1][0] << endl;
    return 0;
}