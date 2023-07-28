package main

import "fmt"

type s [0]int

func main() {
	s1 := new(s)
	s2 := new(s)
	fmt.Println(s1 == s2)
}
