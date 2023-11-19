#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    int n, m;
    std::cin >> n;
    std::cin.ignore();  // Игнорируем перевод строки
    std::string input1, input2;
    std::getline(std::cin, input1);
    std::cin >> m;
    std::cin.ignore();  // Игнорируем перевод строки
    std::getline(std::cin, input2);

    // Разбиваем входные строки на слова и помещаем их в множества
    std::set<std::string> set1, set2;
    std::string word;
    std::istringstream iss1(input1);
    while (iss1 >> word) {
        set1.insert(word);
    }
    std::istringstream iss2(input2);
    while (iss2 >> word) {
        set2.insert(word);
    }

    // Находим общие слова
    std::vector<std::string> commonWords;
    for (const std::string& word : set1) {
        if (set2.count(word) > 0) {
            commonWords.push_back(word);
        }
    }

    // Если есть общие слова, сортируем их и выводим
    if (!commonWords.empty()) {
        std::sort(commonWords.begin(), commonWords.end());
        for (const std::string& word : commonWords) {
            std::cout << word << ' ';
        }
        std::cout << std::endl;
    } else {
        // В противном случае выводим -1
        std::cout << "-1" << std::endl;
    }

    return 0;
}
