#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    // Открываем файл "data.json" для чтения
    std::ifstream file("data.json");
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла:" << std::endl;
        return 1;
    }

    // Читаем JSON из файла
    json data;
    file >> data;
    file.close();

    // Считываем идентификатор пользователя из ввода
    int userID;
    std::cin >> userID;

    // Инициализируем счетчик завершенных задач
    int completedTasks = 0;

    for (const auto& project : data) {
        for (const auto& task : project["tasks"]) {
            if (task["user_id"] == userID && task["completed"]) {
                completedTasks++;
            }
        }
    }

    // Вывод результата
    std::cout << completedTasks << std::endl;

    return 0;
}
