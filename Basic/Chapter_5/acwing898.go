package main

import "fmt"

const maxn, inf int = 510, 1 << 30

var f, a [maxn][maxn]int

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			fmt.Scanf("%d", &a[i][j])
		}
	}
	for i := 0; i <= n; i++ {
		for j := 0; j <= n; j++ {
			f[i][j] = -inf
		}
	}
	f[1][1] = a[1][1]
	for i := 2; i <= n; i++ {
		for j := 1; j <= i; j++ {
			f[i][j] = a[i][j] + max(f[i-1][j-1], f[i-1][j])
		}
	}
	ans := -inf
	for i := 1; i <= n; i++ {
		ans = max(ans, f[n][i])
	}
	fmt.Println(ans)
}
