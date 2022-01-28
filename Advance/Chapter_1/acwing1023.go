package main

import "fmt"

const maxn int = 1010

var v [4]int = [4]int{10, 20, 50, 100}
var f [maxn]int

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	f[0] = 1
	for i := 0; i < 4; i++ {
		for j := v[i]; j <= n; j++ {
			f[j] += f[j-v[i]]
		}
	}
	fmt.Println(f[n])
}
