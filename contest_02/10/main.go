package main

import "fmt"

func shift(data []int, steps int) {
	length := len(data)
	steps = steps % length

	if steps < 0 {
		steps = -steps
		for i := 0; i < steps; i++ {
			temp := data[0]
			copy(data[:], data[1:])
			data[length-1] = temp
		}
	} else {
		for i := 0; i < steps; i++ {
			temp := data[length-1]
			copy(data[1:], data[:length-1])
			data[0] = temp
		}
	}
}

func main() {
	var steps int
	fmt.Scan(&steps)

	var data [10]int
	for index := range data {
		fmt.Scan(&data[index])
	}

	shift(data[:], steps)
	for _, value := range data {
		fmt.Printf("%d ", value)
	}
}

