package main

import "fmt"

const N, M int = 510, 6010

var (
	f       [M]int
	v, w, s [N]int
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
		_, err := fmt.Scanf("%d%d%d", &v[i], &w[i], &s[i])
		if err != nil {
			fmt.Scanf("%d%d%d", &v[i], &w[i], &s[i])
		}
	}
	for i := 1; i <= n; i++ {
		for j := m; j >= v[i]; j-- {
			for k := 1; k <= s[i] && k*v[i] <= j; k++ {
				f[j] = max(f[j], f[j-k*v[i]]+k*w[i])
			}
		}
	}
	fmt.Println(f[m])
}
