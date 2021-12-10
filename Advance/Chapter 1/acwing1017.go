package main

import "fmt"

const maxn, inf int = 110, 1 << 30

var f [maxn][maxn]int

func min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i <= n; i++ {
		for j := 0; j <= n; j++ {
			f[i][j] = inf
		}
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			fmt.Scanf("%d", &f[i][j])
			if !(i == 1 && j == 1) {
				f[i][j] += min(f[i-1][j], f[i][j-1])
			}
		}
	}
	fmt.Println(f[n][n])
}
