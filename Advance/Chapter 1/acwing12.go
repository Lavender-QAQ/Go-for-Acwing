package main

import "fmt"

const maxn int = 1010

var (
	f    [maxn][maxn]int
	v, w [maxn]int
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
		fmt.Scanf("%d%d", &v[i], &w[i])
	}
	for i := n; i >= 1; i-- {
		for j := 0; j <= m; j++ {
			f[i][j] = f[i+1][j]
			if j >= v[i] {
				f[i][j] = max(f[i][j], f[i+1][j-v[i]]+w[i])
			}
		}
	}
	j := m
	for i := 1; i <= n; i++ {
		if j >= v[i] && f[i][j] == f[i+1][j-v[i]]+w[i] {
			j -= v[i]
			fmt.Printf("%d ", i)
		}
	}
	fmt.Println()
}
