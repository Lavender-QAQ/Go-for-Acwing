package main

import "fmt"

const maxn int = 110

var f [maxn][maxn]int

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var T, n, m int
	fmt.Scanf("%d", &T)
	for T > 0 {
		T--
		fmt.Scanf("%d%d", &n, &m)
		for i := 1; i <= n; i++ {
			for j := 1; j <= m; j++ {
				fmt.Scanf("%d", &f[i][j])
				f[i][j] += max(f[i-1][j], f[i][j-1])
			}
		}
		fmt.Println(f[n][m])
	}
}
