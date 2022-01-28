package main

import "fmt"

const N, M int = 20, 3010

var f [M]int

func main() {
	var n, m, v int
	f[0] = 1
	fmt.Scanf("%d%d", &n, &m)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &v)
		for j := v; j <= m; j++ {
			f[j] += f[j-v]
		}
	}
	fmt.Println(f[m])
}
