package main

import "fmt"

const N, M int = 40, 20010

var (
	v [N]int
	f [M]int
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
	fmt.Scanf("%d", &m)
	fmt.Scanf("%d", &n)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &v[i])
	}
	for i := 1; i <= n; i++ {
		for j := m; j >= v[i]; j-- {
			f[j] = max(f[j], f[j-v[i]]+v[i])
		}
	}
	fmt.Println(m - f[m])
}
