package main

import "fmt"

const maxn, inf, mod int = 1010, 1 << 30, 1e9 + 7

var f, g [maxn]int

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func init() {
	for i := 0; i < maxn; i++ {
		f[i] = -inf
	}
}

func main() {
	var n, m, v, w int
	f[0], g[0] = 0, 1
	fmt.Scanf("%d%d", &n, &m)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d%d", &v, &w)
		for j := m; j >= v; j-- {
			if f[j] < f[j-v]+w {
				f[j], g[j] = f[j-v]+w, g[j-v]
			} else if f[j] == f[j-v]+w {
				g[j] += g[j-v]
				g[j] %= mod
			}
		}
	}
	ans, cnt := 0, 0
	for i := 0; i <= m; i++ {
		ans = max(ans, f[i])
	}
	for i := 0; i <= m; i++ {
		if ans == f[i] {
			cnt += g[i]
			cnt %= mod
		}
	}
	fmt.Println(cnt)
}
