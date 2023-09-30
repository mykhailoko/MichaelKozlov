package main

import (
	"fmt"
)

func main() {
	var swim, wing, neck string
	fmt.Scanln(&swim, &wing, &neck)

	if swim == "Да" && wing == "Да" && neck == "Да" {
		fmt.Print("Утка")
	} else if swim == "Да" && wing == "Да" {
		fmt.Print("Пингвин")
	} else if swim == "Да" && neck == "Да" {
		fmt.Print("Плезиозавры")
	} else if swim == "Да" {
		fmt.Print("Дельфин")
	} else if wing == "Да" && neck == "Да" {
		fmt.Print("Страус")
	} else if wing == "Да" {
		fmt.Print("Курица")
	} else if neck == "Да" {
		fmt.Print("Жираф")
	} else {
		fmt.Print("Кот")
	}
}

