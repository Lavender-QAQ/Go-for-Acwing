package main

import "fmt"

const maxn int = 110

var (
	v, w, s [maxn]int
	f       [maxn][maxn]int
)

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var n, m int
	fmt.Scanf("%d%d", &n, &m)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d%d%d", &v[i], &w[i], &s[i])
	}
	for i := 1; i <= n; i++ {
		for j := 0; j <= m; j++ {
			f[i][j] = f[i-1][j]
			for k := 0; k <= s[i] && k*v[i] <= j; k++ {
				f[i][j] = max(f[i][j], f[i-1][j-k*v[i]]+k*w[i])
			}
		}
	}
	fmt.Println(f[n][m])
}
