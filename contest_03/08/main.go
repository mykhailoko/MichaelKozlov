package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	var unique int
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		unique ^= num
	}

	fmt.Println(unique)
}
