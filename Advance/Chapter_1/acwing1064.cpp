#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 12, M = 1 << 10, K = 110;

typedef long long ll;

ll f[N][K][M];
int cnt[M];
vector<int> h[M];
vector<int> state;

inline bool check(int x) {
    return x >> 1 & x;
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
    int n, k;
    cin >> n >> k;
    memset(f, 0, sizeof f);
    for (int i = 0;i < 1 << n;i++) {
        if (check(i)) continue;
        state.push_back(i);
        cnt[i] = count(i);
        for (int j = 0;j < 1 << n;j++) {
            if (check(j)) continue;
            if (i & j || check(i | j)) continue;
            h[i].push_back(j);
        }
    }
    f[0][0][0] = 1;
    for (int i = 1;i <= n + 1;i++)
        for (int j = 0;j <= k;j++)
            for (int& a : state)
                for (int& b : h[a])
                    if (j >= cnt[b]) {
                        f[i][j][a] += f[i - 1][j - cnt[b]][b];
                    }
    cout << f[n + 1][k][0] << endl;
    return 0;
}