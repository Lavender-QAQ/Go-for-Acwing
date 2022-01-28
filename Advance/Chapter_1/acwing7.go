package main

import "fmt"

const maxn int = 1010

var f [maxn]int

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var n, m, v, w, s int
	fmt.Scanf("%d%d", &n, &m)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d%d%d", &v, &w, &s)
		if s == -1 {
			for j := m; j >= v; j-- {
				f[j] = max(f[j], f[j-v]+w)
			}
		} else if s == 0 {
			for j := v; j <= m; j++ {
				f[j] = max(f[j], f[j-v]+w)
			}
		} else {
			for k := 1; k <= s; k *= 2 {
				for j := m; j >= k*v; j-- {
					f[j] = max(f[j], f[j-k*v]+k*w)
				}
				s -= k
			}
			if s > 0 {
				for j := m; j >= s*v; j-- {
					f[j] = max(f[j], f[j-s*v]+s*w)
				}
			}
		}
	}
	fmt.Println(f[m])
}
