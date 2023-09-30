#include <iostream>
#include <string>
#include <set>

int main() {
    std::string input;
    std::set<std::string> words;
    std::set<std::string> duplicate_words;

    while (true) {
        std::cin >> input;

        if (input == "end") {
            break;
        }

        if (words.count(input) > 0) {
            duplicate_words.insert(input);
        } else {
            words.insert(input);
        }
    }

    for (const std::string& word : duplicate_words) {
        std::cout << word << " ";
    }

    std::cout << std::endl;

    return 0;
}

