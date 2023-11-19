package main

import "fmt"

func main() {
	var n, X int
	fmt.Scan(&n, &X)

	numbers := make(map[int]bool) // Хэш-таблица для хранения чисел

	var result []int
	found := false

	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)

		// Проверяем, есть ли число, которое в паре с текущим числом даст значение X
		if numbers[X-num] {
			result = append(result, num)
			result = append(result, X-num)
			found = true
			break
		}

		// Добавляем текущее число в хэш-таблицу
		numbers[num] = true
	}

	if found {
		// Если найдена пара, выводим результат
		if result[0] < result[1] {
			fmt.Println(result[0], result[1])
		} else {
			fmt.Println(result[1], result[0])
		}
	} else {
		// Если пара не найдена, выводим два нуля
		fmt.Println(0, 0)
	}
}
