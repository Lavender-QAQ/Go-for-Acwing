#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 410, inf = 0x3f3f3f3f;

int s[maxn], f[maxn][maxn], g[maxn][maxn];

int main() {
    int n;
    cin >> n;
    memset(f, 0x3f, sizeof f);
    memset(g, -0x3f, sizeof g);
    for (int i = 1;i <= n;i++) cin >> s[i], s[i + n] = s[i];
    for (int i = 1;i <= 2 * n;i++) s[i] += s[i - 1], f[i][i] = g[i][i] = 0;
    for (int len = 2;len <= n;len++)
        for (int l = 1;l + len - 1 <= 2 * n;l++) {
            int r = l + len - 1;
            for (int k = l;k < r;k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    int mx = -inf, mi = inf;
    for (int i = 1;i <= n;i++) {
        mi = max(mi, f[i][i + n - 1]);
        mx = min(mx, g[i][i + n - 1]);
    }
    cout << mi << endl << mx << endl;
    return 0;
}