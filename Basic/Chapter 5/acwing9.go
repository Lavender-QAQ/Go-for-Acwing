package main

import "fmt"

const maxn int = 110

var (
	v, w [maxn][maxn]int
	s, f [maxn]int
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
		fmt.Scanf("%d", &s[i])
		for j := 0; j < s[i]; j++ {
			fmt.Scanf("%d%d", &v[i][j], &w[i][j])
		}
	}
	for i := 1; i <= n; i++ {
		for j := m; j >= 0; j-- {
			for k := 0; k < s[i]; k++ {
				if j >= v[i][k] {
					f[j] = max(f[j], f[j-v[i][k]]+w[i][k])
				}
			}
		}
	}
	fmt.Println(f[m])
}
