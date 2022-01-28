package main

import "fmt"

const N, M int = 15, 20

var (
	f, g [N][M]int
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
		for j := 1; j <= m; j++ {
			fmt.Scanf("%d", &g[i][j])
		}
	}
	for i := 1; i <= n; i++ {
		for j := 0; j <= m; j++ {
			for k := 0; k <= j; k++ {
				f[i][j] = max(f[i][j], f[i-1][j-k]+g[i][k])
			}
		}
	}
	fmt.Println(f[n][m])
	j := m
	for i := n; i >= 1; i-- {
		for k := 0; k <= j; k++ {
			if f[i][j] == f[i-1][j-k]+g[i][k] {
				j -= k
				fmt.Printf("%d %d\n", i, k)
				break
			}
		}
	}
}
