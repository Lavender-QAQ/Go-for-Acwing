package main

import "fmt"

const maxn, inf int = 1e5 + 10, 0x3f3f3f3f

var (
	a [maxn]int
	f [maxn][3]int
)

func init() {
	for i := 0; i < maxn; i++ {
		for j := 0; j < 3; j++ {
			f[i][j] = -inf
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
	var n int
	fmt.Scanf("%d", &n)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	f[0][2] = 0
	for i := 1; i <= n; i++ {
		f[i][0] = max(f[i-1][0], f[i-1][2]-a[i])
		f[i][1] = f[i-1][0] + a[i]
		f[i][2] = max(f[i-1][2], f[i-1][1])
	}
	ans := 0
	for i := 1; i <= n; i++ {
		ans = max(ans, f[i][1])
	}
	fmt.Println(ans)
}
