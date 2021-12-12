package main

import "fmt"

const maxn int = 110

var a, f [maxn]int

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var T, n int
	fmt.Scanf("%d", &T)
	for T > 0 {
		T--
		ans := 0
		fmt.Scanf("%d", &n)
		for i := 1; i <= n; i++ {
			fmt.Scanf("%d", &a[i])
			f[i] = 1
			for j := 1; j < i; j++ {
				if a[i] < a[j] {
					f[i] = max(f[i], f[j]+1)
				}
			}
			ans = max(ans, f[i])
		}
		for i := n; i >= 1; i-- {
			f[i] = 1
			for j := n; j > i; j-- {
				if a[j] > a[i] {
					f[i] = max(f[i], f[j]+1)
				}
			}
			ans = max(ans, f[i])
		}
		fmt.Println(ans)
	}
}
