package main

import "fmt"

const N, K, inf int = 1e5 + 10, 110, 0x3f3f3f3f

var (
	f [N][K][2]int
	a [N]int
)

func init() {
	for i := 0; i < N; i++ {
		for j := 0; j < K; j++ {
			for k := 0; k < 2; k++ {
				f[i][j][k] = -inf
			}
		}
	}
}

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
		fmt.Scanf("%d", &a[i])
	}
	for i := 0; i <= n; i++ {
		f[i][0][0] = 0
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1]+a[i])
			f[i][j][1] = max(f[i-1][j][1], f[i-1][j-1][0]-a[i])
		}
	}
	ans := 0
	for i := 0; i <= m; i++ {
		ans = max(ans, f[n][i][0])
	}
	fmt.Println(ans)
}
