package main

import (
	"bufio"
	"fmt"
	"os"
)

func isLucky(ticket string) bool {
	if len(ticket) != 6 {
		return false
	}

	sumFirstHalf := 0
	sumSecondHalf := 0

	for i := 0; i < 6; i++ {
		digit := int(ticket[i] - '0')

		if digit < 0 || digit > 9 {
			return false
		}

		if i < 3 {
			sumFirstHalf += digit
		} else {
			sumSecondHalf += digit
		}
	}

	return sumFirstHalf == sumSecondHalf
}

func main() {
	number, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isLucky(number[:len(number)-1]) { // Обрезаем \n в конце строки
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

