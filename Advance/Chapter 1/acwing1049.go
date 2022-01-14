package main

import "fmt"

const maxn int = 1e5 + 10

var (
	a [maxn]int
	f [maxn][2]int
)

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var T, n int
	fmt.Scanf("%d", &T)
	for c := 0; c < T; c++ {
		fmt.Scanf("%d", &n)
		for i := 1; i <= n; i++ {
			fmt.Scanf("%d", &a[i])
		}
		for i := 1; i <= n; i++ {
			f[i][0] = max(f[i-1][0], f[i-1][1])
			f[i][1] = f[i-1][0] + a[i]
		}
		fmt.Println(max(f[n][0], f[n][1]))
	}
}
