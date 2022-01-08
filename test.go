package main

import "fmt"

func main() {
	var a, b, c, d int
	_, err := fmt.Scanf("%d%d", &a, &b)
	_, err = fmt.Scanf("%d%d", &c, &d)
	if err != nil {
		fmt.Scanf("%d%d",&c,&d)
	}
	fmt.Println(a,b,c,d)
}
