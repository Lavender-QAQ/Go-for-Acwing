package main

import (
	"fmt"
	"sort"
)

const N, M int = 110, 25010

var (
	f [M]int
	v [N]int
)

func main() {
	var T, n int
	_, err := fmt.Scanf("%d", &T)
	if err != nil {
		fmt.Scanf("%d", &T)
	}
	for T > 0 {
		T--
		for i := 0; i < M; i++ {
			f[i] = 0
		}
		f[0] = 1
		_, err = fmt.Scanf("%d", &n)
		if err != nil {
			fmt.Scanf("%d", &n)
		}
		for i := 1; i <= n; i++ {
			_, err = fmt.Scanf("%d", &v[i])
			if err != nil {
				fmt.Scanf("%d", &v[i])
			}
		}
		sort.Sort(sort.IntSlice(v[1 : n+1]))
		m, ans := v[n], 0
		for i := 1; i <= n; i++ {
			if f[v[i]] == 0 {
				ans++
			}
			for j := v[i]; j <= m; j++ {
				f[j] += f[j-v[i]]
			}
		}
		fmt.Println(ans)
	}
}
