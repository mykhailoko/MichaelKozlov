package main

import (
	"fmt"
)

type Matrix struct {
	data [][]int
}

// Создает и возвращает новую матрицу с количеством строк rows и столбцов cols.
// Все элементы матрицы заполняются значением value.
func NewMatrix(rows, cols, value int) Matrix {
	data := make([][]int, rows)
	for i := 0; i < rows; i++ {
		data[i] = make([]int, cols)
		for j := 0; j < cols; j++ {
			data[i][j] = value
		}
	}
	return Matrix{data: data}
}

// Возвращает количество строк в матрице m.
func (m *Matrix) Rows() int {
	return len(m.data)
}

// Возвращает количество столбцов в матрице m.
func (m *Matrix) Cols() int {
	if len(m.data) > 0 {
		return len(m.data[0])
	}
	return 0
}

// Устанавливает элементу матрицы m с индексом (row, col) значение равное value.
func (m *Matrix) Set(row, col, value int) {
	m.data[row][col] = value
}

// Возвращает значение элемента матрицы m с индексом (row, col).
func (m *Matrix) Get(row, col int) int {
	return m.data[row][col]
}

// Выполняет свёртку матрицы m с ядром core.
// Возвращает новую матрицу.
func (m *Matrix) Convolution(core *Matrix) Matrix {
	rows := m.Rows() - core.Rows() + 1
	cols := m.Cols() - core.Cols() + 1
	result := NewMatrix(rows, cols, 0)

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			sum := 0
			for ci := 0; ci < core.Rows(); ci++ {
				for cj := 0; cj < core.Cols(); cj++ {
					sum += m.Get(i+ci, j+cj) * core.Get(ci, cj)
				}
			}
			result.Set(i, j, sum)
		}
	}

	return result
}

// Выполняет умножение матрицы a на матрицу b.
// Возвращает новую матрицу.
func (a *Matrix) Multiplication(b *Matrix) Matrix {
	rowsA, colsA := a.Rows(), a.Cols()
	rowsB, colsB := b.Rows(), b.Cols()

	if colsA != rowsB {
		panic("Невозможно выполнить умножение матриц: неправильные размеры")
	}

	result := NewMatrix(rowsA, colsB, 0)

	for i := 0; i < rowsA; i++ {
		for j := 0; j < colsB; j++ {
			sum := 0
			for k := 0; k < colsA; k++ {
				sum += a.Get(i, k) * b.Get(k, j)
			}
			result.Set(i, j, sum)
		}
	}

	return result
}

// Добавляет в конец матрицы m дополнительную строку заполненную значением value.
func (m *Matrix) AddRow(value int) {
	newRow := make([]int, m.Cols())
	for i := range newRow {
		newRow[i] = value
	}
	m.data = append(m.data, newRow)
}

// Добавляет в конец матрицы m дополнительный столбец заполненный значением value.
func (m *Matrix) AddCol(value int) {
	for i := range m.data {
		m.data[i] = append(m.data[i], value)
	}
}

// Возвращает строковое представление матрицы m.
func (m *Matrix) String() string {
	result := ""
	for i := 0; i < m.Rows(); i++ {
		for j := 0; j < m.Cols(); j++ {
			result += fmt.Sprintf("%d", m.Get(i, j))
			if j < m.Cols()-1 {
				result += " "
			}
		}
		if i < m.Rows()-1 {
			result += "\n"
		}
	}
	return result
}


func main() {
	var rowsFirst, colsFirst, firstInitVal,
		rowsCore, colsCore int

	fmt.Scan(&rowsFirst, &colsFirst, &firstInitVal)
	first := NewMatrix(rowsFirst, colsFirst, firstInitVal)
	for i := 0; i < first.Rows(); i++ {
		for j := 0; j < first.Cols(); j++ {
			var t int
			fmt.Scan(&t)
			first.Set(i, j, t)
		}
	}

	fmt.Scan(&rowsCore, &colsCore)
	core := NewMatrix(rowsCore, colsCore, 0)
	for i := 0; i < core.Rows(); i++ {
		for j := 0; j < core.Cols(); j++ {
			var t int
			fmt.Scan(&t)
			core.Set(i, j, t)
		}
	}

	conv := first.Convolution(&core)

	conv.AddRow(1)
	conv.AddCol(1)
	conv.AddCol(1)

	mult := conv.Multiplication(&first)

	fmt.Print(mult)
}

