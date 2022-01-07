package main

import "fmt"

const N, M, inf int = 80, 22, 1 << 30

var f [M][N]int

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var n, m, k, a, b, c int
	fmt.Scanf("%d%d", &m, &n)
	fmt.Scanf("%d", &k)
	for i := 0; i <= M-1; i++ {
		for j := 0; j <= N-1; j++ {
			f[i][j] = inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= k; i++ {
		fmt.Scanf("%d%d%d", &a, &b, &c)
		for j := M - 1; j >= 0; j-- {
			for t := N - 1; t >= 0; t-- {
				f[j][t] = min(f[j][t], f[max(0, j-a)][max(0, t-b)]+c)
			}
		}
	}
	ans := inf
	for i := m; i < M; i++ {
		for j := n; j < N; j++ {
			ans = min(ans, f[i][j])
		}
	}
	fmt.Println(ans)
}
