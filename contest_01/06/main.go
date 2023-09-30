package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)

	denominations := []int{5000, 1000, 500, 200, 100}
	counts := make([]int, len(denominations))

	for i, denom := range denominations {
		counts[i] = N / denom
		N %= denom
	}

	for _, count := range counts {
		fmt.Print(count, " ")
	}
}

