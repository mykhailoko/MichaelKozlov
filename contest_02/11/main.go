package main

import "fmt"

const rows int = 9
const cols int = 9

func isValidSudoku(board [rows][cols]int) bool {
	for i := 0; i < rows; i++ {
		rowSet := make(map[int]bool)
		colSet := make(map[int]bool)
		for j := 0; j < cols; j++ {

			if board[i][j] != 0 {
				if rowSet[board[i][j]] {
					return false
				}
				rowSet[board[i][j]] = true
			}

			if board[j][i] != 0 {
				if colSet[board[j][i]] {
					return false
				}
				colSet[board[j][i]] = true
			}
		}
	}

	for i := 0; i < rows; i += 3 {
		for j := 0; j < cols; j += 3 {
			squareSet := make(map[int]bool)
			for x := i; x < i+3; x++ {
				for y := j; y < j+3; y++ {
					if board[x][y] != 0 {
						if squareSet[board[x][y]] {
							return false
						}
						squareSet[board[x][y]] = true
					}
				}
			}
		}
	}

	return true
}

func main() {
	var bord [rows][cols]int

	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			fmt.Scanf("%c", &bord[row][col]) // Считываем один символ
			bord[row][col] -= '0'            // Чтобы из ASCII кода символа получить цифру
		}
		fmt.Scanf("\n")
	}

	if isValidSudoku(bord) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

