package main

import "fmt"

const maxn int = 110

var (
	g [maxn][maxn]int
	f [2*maxn][maxn][maxn]int
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
		for j := 1; j <= m; j++ {
			_, err := fmt.Scanf("%d", &g[i][j])
			for err != nil {
				_, err = fmt.Scanf("%d", &g[i][j])
			}
		}
	}

	for k := 2; k <= n+m; k++ {
		for i1 := 1; i1 <= n && i1 < k; i1++ {
			for i2 := 1; i2 <= n && i2 < k; i2++ {
				j1, j2 := k-i1, k-i2
				t := g[i1][j1]
				if i1 != i2 {
					t += g[i2][j2]
				}
				var x *int = &f[k][i1][i2]
				*x = max(*x, f[k-1][i1-1][i2-1]+t)
				*x = max(*x, f[k-1][i1-1][i2]+t)
				*x = max(*x, f[k-1][i1][i2-1]+t)
				*x = max(*x, f[k-1][i1][i2]+t)
			}
		}
	}
	fmt.Println(f[n+m][n][n])
}
