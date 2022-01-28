package main

import "fmt"

const N, M int = 100, 32010

type stuff struct {
	v, w int
}

var (
	f       [M]int
	master  [N]stuff
	servent [N][]stuff
)

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var n, m, v, p, q int
	fmt.Scanf("%d%d", &m, &n)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d%d%d", &v, &p, &q)
		if q == 0 {
			master[i] = stuff{
				v: v,
				w: v * p,
			}
		} else {
			servent[q] = append(servent[q], stuff{
				v: v,
				w: v * p,
			})
		}
	}
	for i := 1; i <= n; i++ {
		if master[i].v > 0 {
			for j := m; j >= 0; j-- {
				for k := 0; k < 1<<len(servent[i]); k++ {
					v, w := master[i].v, master[i].w
					for u := 0; u < len(servent[i]); u++ {
						if (k>>u)&1 == 1 {
							v += servent[i][u].v
							w += servent[i][u].w
						}
					}
					if j >= v {
						f[j] = max(f[j], f[j-v]+w)
					}
				}
			}
		}
	}
	fmt.Println(f[m])
}
