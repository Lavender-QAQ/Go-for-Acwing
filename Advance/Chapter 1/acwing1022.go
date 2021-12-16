package main

import "fmt"

const maxn int = 1010

var f [maxn][maxn]int

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var n, m, c, a, b int
	fmt.Scanf("%d%d%d", &n, &m, &c)
	for i := 1; i <= c; i++ {
		fmt.Scanf("%d%d", &a, &b)
		for j := m - 1; j >= b; j-- {
			for k := n; k >= a; k-- {
				f[j][k] = max(f[j][k], f[j-b][k-a]+1)
			}
		}
	}
	fmt.Printf("%d ", f[m-1][n])
	ans := m - 1
	for ans > 0 && f[ans-1][n] == f[m-1][n] {
		ans--
	}
	fmt.Println(m - ans)
}
