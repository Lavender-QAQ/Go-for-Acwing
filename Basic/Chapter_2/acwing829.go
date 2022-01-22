package main

import "fmt"

const maxn int = 1e5 + 10

var (
	s      [maxn]int
	hh, rr int
)

func push(x int) {
	s[rr] = x
	rr++
}

func pop() {
	if !empty() {
		hh++
	}
}

func query() int {
	return s[hh]
}

func empty() bool {
	return hh == rr
}

func main() {
	var (
		n, x int
		str  string
	)
	fmt.Scanf("%d", &n)
	for n > 0 {
		n--
		fmt.Scanf("%s", &str)
		if str == "push" {
			fmt.Scanf("%d", &x)
			push(x)
		} else if str == "query" {
			fmt.Println(query())
		} else if str == "pop" {
			pop()
		} else {
			if empty() {
				fmt.Println("YES")
			} else {
				fmt.Println("NO")
			}
		}
	}
}
