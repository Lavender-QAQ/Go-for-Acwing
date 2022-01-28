package main

import "fmt"

const N, M int = 30, 30010

var (
	f    [M]int
	v, w [N]int
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
	fmt.Scanf("%d%d", &m, &n)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d%d", &v[i], &w[i])
		w[i] *= v[i]
	}
	for i := 1; i <= n; i++ {
		for j := m; j >= v[i]; j-- {
			f[j] = max(f[j], f[j-v[i]]+w[i])
		}
	}
	fmt.Println(f[m])
}
