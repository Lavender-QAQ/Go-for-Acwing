package main

import "fmt"

func main() {
	var a = [2]int{1, 2}
	var b = [2]int{0, 0}
	copy(b[:], a[:])
	fmt.Println(a,b)
}
