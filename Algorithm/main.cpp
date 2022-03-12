#include <iostream>
#include <map>
using namespace std;

const int maxn = 1e5 + 10;

int tree[maxn], squ[maxn], n, m, ans;

map<int, int> mp_tree;
map<int, int> mp_squ;

void dfs(int u, map<int, int>& mp_tree, map<int, int>& mp_squ) {
    if (2 * u <= n) dfs(2 * u, mp_tree, mp_squ);
    if (2 * u + 1 <= n + 1) dfs(2 * u, mp_tree, mp_squ);
    if (tree[u]) {
        for (auto& it : mp_squ) {
        }
    } else if (squ[u]) {

    }
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> tree[i];
    for (int i = 0;i < m;i++) squ[i]++;
    for (int i = 1;i <= n;i++) {
        if (tree[i] >= squ[i]) tree[i] -= squ[i], squ[i] = 0;
        else squ[i] -= tree[i], tree[i] = 0;
    }
    dfs(1);
    return 0;
}