package main

import "fmt"

const maxn, maxm int = 1010, 110

var (
	v, m, w [maxn]int
	f       [maxm][maxm]int
)

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var n, V, M int
	fmt.Scanf("%d%d%d", &n, &V, &M)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d%d%d", &v[i], &m[i], &w[i])
	}
	for i := 1; i <= n; i++ {
		for j := V; j >= v[i]; j-- {
			for k := M; k >= m[i]; k-- {
				f[j][k] = max(f[j][k], f[j-v[i]][k-m[i]]+w[i])
			}
		}
	}
	fmt.Println(f[V][M])
}
