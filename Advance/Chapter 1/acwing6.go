package main

import "fmt"

const M int = 20010

var f, g, q [M]int

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
		copy(g[:], f[:])
		for j := 0; j < v; j++ {
			hh, rr := 0, 0
			for k := j; k <= m; k += v {
				if hh < rr && q[hh] < k-s*v {
					hh++
				}
				if hh < rr {
					f[k] = max(f[k], g[q[hh]]+(k-q[hh])/v*w)
				}
				for hh < rr && g[q[rr-1]]-(q[rr-1]-j)/v*w <= g[k]-(k-j)/v*w {
					rr--
				}
				q[rr] = k
				rr++
			}
		}
	}
	fmt.Println(f[m])
}
