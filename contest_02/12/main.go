package main

import "fmt"

// Функция для заполнения игрового поля сапёр.
func fill(field [][]int) {
	rows := len(field)
	cols := len(field[0])

	// Создаем смещения для соседних ячеек.
	dx := []int{-1, -1, -1, 0, 0, 1, 1, 1}
	dy := []int{-1, 0, 1, -1, 1, -1, 0, 1}

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if field[i][j] == -1 {
				// Пропускаем ячейки с минами.
				continue
			}
			countMines := 0
			for k := 0; k < 8; k++ {
				ni := i + dx[k]
				nj := j + dy[k]
				if ni >= 0 && ni < rows && nj >= 0 && nj < cols && field[ni][nj] == -1 {
					// Если соседняя ячейка содержит мину, увеличиваем счетчик мин.
					countMines++
				}
			}
			// Заполняем ячейку с количеством мин вокруг.
			field[i][j] = countMines
		}
	}
}

func main() {
	var rows, cols int
	fmt.Scanf("%d %d\n", &rows, &cols)

	// Создаём срез и заполняем его данными о расположении мин
	maze := make([][]int, rows, rows)
	for i := range maze {
		maze[i] = make([]int, cols, cols)
		for j := range maze[i] {
			fmt.Scanf("%d", &maze[i][j])
		}
	}

	// Заполняем игровое поле подсказками
	fill(maze)

	// Выводим на экран
	for _, row := range maze {
		for _, cell := range row {
			fmt.Printf("%3d", cell)
		}
		fmt.Println()
	}
}

