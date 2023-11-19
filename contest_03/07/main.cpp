#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

struct WordInfo {
    std::string word;
    int count;

    bool operator<(const WordInfo& other) const {
        if (count == other.count) {
            return word < other.word;
        }
        return count > other.count;
    }
};

int main() {
    std::ifstream file("data.txt");
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла data.txt" << std::endl;
        return 1;
    }

    std::map<std::string, std::map<std::string, int>> wordFollowers;

    std::string word;
    std::string targetWord;
    std::vector<std::string> nextWords;

    while (file >> word) {
        if (word == "stopword") {
            break; // Прерываем чтение при достижении "stopword"
        }

        if (!targetWord.empty()) {
            // Добавляем слово, следующее за targetWord, в контейнер wordFollowers
            wordFollowers[targetWord][word]++;
        }

        targetWord = word;
    }

    // Считываем вводное слово
    std::string inputWord;
    std::cin >> inputWord;

    if (wordFollowers.find(inputWord) != wordFollowers.end()) {
        std::vector<WordInfo> sortedWords;

        for (const auto& entry : wordFollowers[inputWord]) {
            sortedWords.push_back({entry.first, entry.second});
        }

        std::sort(sortedWords.begin(), sortedWords.end());

        for (size_t i = 0; i < sortedWords.size() && i < 3; ++i) {
            nextWords.push_back(sortedWords[i].word);
        }
    }

    if (nextWords.empty()) {
        std::cout << "-" << std::endl;
    } else {
        for (const std::string& nextWord : nextWords) {
            std::cout << nextWord << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
