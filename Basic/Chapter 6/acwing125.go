package main

import (
	"fmt"
	"sort"
)

const maxn int = 50010

type cow struct {
	w, s int
}

type cows []cow

func (c cows) Len() int {
	return len(c)
}

func (c cows) Less(i, j int) bool {
	return c[i].s+c[i].w < c[j].s+c[j].w
}

func (c cows) Swap(i, j int) {
	c[i], c[j] = c[j], c[i]
}

var a [maxn]cow

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
	for i := 0; i < n; i++ {
		fmt.Scanf("%d%d", &a[i].w, &a[i].s)
	}
	sort.Sort(cows(a[:n]))
	var ans, w int = -2e9, 0
	for i := 0; i < n; i++ {
		ans = max(ans, w-a[i].s)
		w += a[i].w
	}
	fmt.Println(ans)
}
