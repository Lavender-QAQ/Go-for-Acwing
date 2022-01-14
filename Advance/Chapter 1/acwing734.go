package main

import (
	"fmt"
	"sort"
)

const N, M, inf int = 110, 1e4 + 10, 1 << 30

type stone struct {
	s, e, l int
}

type stones []stone

func (s stones) Len() int {
	return len(s)
}

func (s stones) Less(i, j int) bool {
	return s[i].s*s[j].l < s[j].s*s[i].l
}

func (s stones) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

var (
	a [N]stone
	f [M]int
)

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func reset() {
	for i := 0; i < M; i++ {
		f[i] = -inf
	}
}

func main() {
	var T, n int
	fmt.Scanf("%d", &T)
	for c := 1; c <= T; c++ {
		reset()
		m := 0
		fmt.Scanf("%d", &n)
		for i := 1; i <= n; i++ {
			fmt.Scanf("%d%d%d", &a[i].s, &a[i].e, &a[i].l)
			m += a[i].s
		}
		sort.Sort(stones(a[1 : n+1]))
		f[0] = 0
		for i := 1; i <= n; i++ {
			for j := m; j >= a[i].s; j-- {
				f[j] = max(f[j], f[j-a[i].s]+a[i].e-(j-a[i].s)*a[i].l)
			}
		}
		ans := -1
		for i := 0; i <= m; i++ {
			ans = max(ans, f[i])
		}
		fmt.Printf("Case #%d: %d\n", c, ans)
	}
}
