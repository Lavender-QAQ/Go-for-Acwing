package main

import "fmt"

const N, M int = 1e5 + 10, 1e6 + 10

var (
	n, m int
	s, p string
	ne   [N]int
)

func pre_kmp() {
	ne[0], ne[1] = -1, 0
	for i, j := 1, 0; i < n-1; i, j = i+1, j+1 {
		for j > -1 && p[i] != p[j] {
			j = ne[j]
		}
		ne[i+1] = j + 1
	}
}

func kmp() {
	for i, j := 0, 0; i < m; i, j = i+1, j+1 {
		for j > -1 && s[i] != p[j] {
			j = ne[j]
		}
		if j == n-1 {
			fmt.Printf("%d ", i-n+1)
			j = ne[j]
			i, j = i-1, j-1
		}
	}
	fmt.Println()
}

func main() {
	fmt.Scanf("%d", &n)
	fmt.Scanf("%s", &p)
	fmt.Scanf("%d", &m)
	fmt.Scanf("%s", &s)
	pre_kmp()
	kmp()
}
