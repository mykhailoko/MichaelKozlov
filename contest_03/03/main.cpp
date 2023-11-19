#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, m;
    input >> n;
    std::set<std::string> set1;

    for (int i = 0; i < n; ++i) {
        std::string word;
        input >> word;
        set1.insert(word);
    }

    input >> m;
    std::vector<std::string> commonWords;

    for (int i = 0; i < m; ++i) {
        std::string word;
        input >> word;
        if (set1.find(word) != set1.end()) {
            commonWords.push_back(word);
        }
    }

    if (commonWords.empty()) {
        output << "-1" << std::endl;
    } else {
        std::sort(commonWords.begin(), commonWords.end());
        for (const std::string& w : commonWords) {
            output << w << " ";
        }
        output << std::endl;
    }

    return 0;
}
