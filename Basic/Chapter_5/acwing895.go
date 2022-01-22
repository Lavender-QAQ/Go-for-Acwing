package main

import "fmt"

const maxn int = 1010

var f, a [maxn]int

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
	ans := 0
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
		f[i] = 1
		for j := 0; j < i; j++ {
			if a[i] > a[j] {
				f[i] = max(f[i], f[j]+1)
			}
		}
		ans = max(ans, f[i])
	}
	fmt.Println(ans)
}
