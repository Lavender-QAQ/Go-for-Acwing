package main

import "fmt"

const N, M int = 3e5, 2010

var (
	v, w [N]int
	f    [M]int
)

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var n, m, a, b, c int
	fmt.Scanf("%d%d", &n, &m)
	cnt := 0
	for i := 0; i < n; i++ {
		fmt.Scanf("%d%d%d", &a, &b, &c)
		k := 1
		for k <= c {
			cnt++
			v[cnt], w[cnt] = k*a, k*b
			c -= k
			k <<= 1
		}
		if c > 0 {
			cnt++
			v[cnt], w[cnt] = c*a, c*b
		}
	}
	n = cnt
	for i := 1; i <= n; i++ {
		for j := m; j >= v[i]; j-- {
			f[j] = max(f[j], f[j-v[i]]+w[i])
		}
	}
	fmt.Println(f[m])
}
