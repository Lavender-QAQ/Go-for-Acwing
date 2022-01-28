package main

import "fmt"

const maxn int = 110

var (
	f              [maxn][maxn]int
	v, w, e, ne, h [maxn]int
	n, m           int
)

var idx int = 0

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func init() {
	for i := 0; i < maxn; i++ {
		h[i] = -1
	}
}

func add(a, b int) {
	e[idx] = b
	ne[idx] = h[a]
	h[a] = idx
	idx++
}

func dfs(u int) {
	for i := h[u]; i != -1; i = ne[i] {
		son := e[i]
		dfs(son)
		for j := m - v[u]; j >= 0; j-- {
			for k := 0; k <= j; k++ {
				f[u][j] = max(f[u][j], f[u][j-k]+f[son][k])
			}
		}
	}
	for i := m; i >= v[u]; i-- {
		f[u][i] = f[u][i-v[u]] + w[u]
	}
	for i := 0; i < v[u]; i++ {
		f[u][i] = 0
	}
}

func main() {
	var root, p int
	fmt.Scanf("%d%d", &n, &m)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d%d%d", &v[i], &w[i], &p)
		if p == -1 {
			root = i
		} else {
			add(p, i)
		}
	}
	dfs(root)
	fmt.Println(f[root][m])
}
