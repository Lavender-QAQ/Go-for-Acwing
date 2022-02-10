#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define x first
#define y second
typedef pair<double, double> P;

const int N = 20, M = 1 << N;
const double eps = 1e-8;

P q[N];
int path[N][N], f[M];

bool cmp(double x1, double x2) {
    if (fabs(x1 - x2) < eps)
        return true;
    else return false;
}

int main() {
    int T, n, m;
    cin >> T;
    while (T--) {
        memset(path, 0, sizeof path);
        cin >> n >> m;
        for (int i = 0;i < n;i++) cin >> q[i].x >> q[i].y;
        for (int i = 0;i < n;i++) {
            path[i][i] = 1 << i;
            for (int j = 0;j < n;j++) {
                double x1 = q[i].x, y1 = q[i].y, x2 = q[j].x, y2 = q[j].y;
                if (cmp(x1, x2)) continue;
                double a = (y1 / x1 - y2 / x2) / (x1 - x2);
                if (a >= 0) continue;
                double b = y1 / x1 - a * x1;
                for (int k = 0;k < n;k++)
                    if (cmp(a * q[k].x * q[k].x + b * q[k].x, q[k].y))
                        path[i][j] += 1 << k;
            }
        }
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 0;i < (1 << n) - 1;i++) {
            int x = 0;
            for (int j = 0;j < n;j++)
                if (!(i >> j & 1)) {
                    x = j;
                    break;
                }
            for (int j = 0;j < n;j++)
                f[i | path[x][j]] = min(f[i | path[x][j]], f[i] + 1);
        }
        cout << f[(1 << n) - 1] << endl;
    }
    return 0;
}