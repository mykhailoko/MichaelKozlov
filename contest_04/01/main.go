package main

import (
	"encoding/json"
	"fmt"
	"os"
)

type Task struct {
	UserID    int    `json:"user_id"`
	ID        int    `json:"id"`
	Title     string `json:"title"`
	Completed bool   `json:"completed"`
}

type Project struct {
	ProjectID int    `json:"project_id"`
	Tasks     []Task `json:"tasks"`
}

func main() {
	// Открываем файл "data.json" для чтения
	file, err := os.Open("data.json")
	if err != nil {
		fmt.Println("Ошибка при открытии файла:", err)
		return
	}
	defer file.Close()

	// Создаём структуру для хранения данных из файла JSON
	var projects []Project

	// Декодируем JSON из файла в структуру
	decoder := json.NewDecoder(file)
	if err := decoder.Decode(&projects); err != nil {
		fmt.Println("Ошибка при декодировании JSON:", err)
		return
	}

	// Чтение идентификатора пользователя из ввода
	var userID int
	fmt.Scan(&userID)

	// Подсчет завершенных задач для указанного пользователя
	completedTasksCount := 0
	for _, project := range projects {
		for _, task := range project.Tasks {
			if task.UserID == userID && task.Completed {
				completedTasksCount++
			}
		}
	}

	// Вывод результата
	fmt.Println(completedTasksCount)
}
