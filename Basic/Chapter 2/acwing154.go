package main

import "fmt"

const maxn int = 1e6 + 10

var (
	a, q   [maxn]int
	hh, rr int
)

func main() {
	var n, k int
	fmt.Scanf("%d%d", &n, &k)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	for i := 0; i < n; i++ {
		for rr > hh && i-k+1 > q[hh] {
			hh++
		}
		for rr > hh && a[q[rr-1]] >= a[i] {
			rr--
		}
		q[rr] = i
		rr++
		if i >= k-1 {
			fmt.Printf("%d ", a[q[hh]])
		}
	}
	fmt.Println()
	hh, rr = 0, 0
	for i := 0; i < n; i++ {
		for rr > hh && i-k+1 > q[hh] {
			hh++
		}
		for rr > hh && a[q[rr-1]] <= a[i] {
			rr--
		}
		q[rr] = i
		rr++
		if i >= k-1 {
			fmt.Printf("%d ", a[q[hh]])
		}
	}
	fmt.Println()
}
