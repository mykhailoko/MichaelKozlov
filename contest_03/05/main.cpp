#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> wordCount;

    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        wordCount[word]++;
    }

    int maxCount = 0;
    std::vector<std::string> frequentWords;

    for (const auto& pair : wordCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            frequentWords.clear();
            frequentWords.push_back(pair.first);
        } else if (pair.second == maxCount) {
            frequentWords.push_back(pair.first);
        }
    }

    std::sort(frequentWords.begin(), frequentWords.end());

    for (const std::string& word : frequentWords) {
        std::cout << word << " ";
    }

    return 0;
}
