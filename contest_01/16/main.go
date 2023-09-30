package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	values := make([]int, n)
	smoothed := make([]float64, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&values[i])
	}

	for i := 0; i < n; i++ {
		if i == 0 || i == n-1 {
			smoothed[i] = float64(values[i])
		} else {
			smoothed[i] = (float64(values[i-1]) + float64(values[i]) + float64(values[i+1])) / 3.0
		}
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%.10f", smoothed[i])
		if i < n-1 {
			fmt.Print(" ")
		}
	}
}

