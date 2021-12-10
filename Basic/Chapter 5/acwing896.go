package main

import (
	"fmt"
	"sort"
)

const maxn int = 1e5 + 10

var (
	a [maxn]int
	q []int
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	var len int = 0
	for i := 0; i < n; i++ {
		index := sort.Search(len, func(j int) bool { return q[j] >= a[i] })
		if index == len {
			q = append(q, a[i])
			len++
		} else {
			q[index] = a[i]
		}
	}
	fmt.Println(len)
}
