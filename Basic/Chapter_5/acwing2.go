package main

import (
	"fmt"
)

const maxn int = 1010

var (
	w, v, f [maxn]int
)

func max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func main() {
	var n, m int
	fmt.Scanf("%d%d", &n, &m)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d%d", &v[i], &w[i])
	}
	for i := 1; i <= n; i++ {
		for j := m; j >=0 ; j-- {
			if j >= v[i] {
				f[j] = max(f[j], f[j-v[i]]+w[i])
			}
		}
	}
	fmt.Println(f[m])
}
