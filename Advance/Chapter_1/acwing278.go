package main

import "fmt"

const M int = 10010

var f [M]int

func main() {
	var n, m, v int
	f[0] = 1
	fmt.Scanf("%d%d", &n, &m)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &v)
		for j := m; j >= v; j-- {
			f[j] += f[j-v]
		}
	}
	fmt.Println(f[m])
}
