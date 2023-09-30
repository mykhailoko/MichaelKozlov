package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	heights := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&heights[i])
	}

	totalWater := 0

	leftMax := make([]int, n)
	rightMax := make([]int, n)

	leftMax[0] = heights[0]
	for i := 1; i < n; i++ {
		leftMax[i] = max(leftMax[i-1], heights[i])
	}

	rightMax[n-1] = heights[n-1]
	for i := n - 2; i >= 0; i-- {
		rightMax[i] = max(rightMax[i+1], heights[i])
	}

	for i := 0; i < n; i++ {
		trappedWater := min(leftMax[i], rightMax[i]) - heights[i]
		if trappedWater > 0 {
			totalWater += trappedWater
		}
	}

	fmt.Println(totalWater)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
