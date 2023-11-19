#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<std::string, int> userBalances;

    // Переход на следующую строку
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::string line;
        std::getline(std::cin, line);
        size_t pos = line.find(';');
        if (pos != std::string::npos) {
            std::string login = line.substr(0, pos);
            int balance = std::stoi(line.substr(pos + 1));
            userBalances[login] = balance;
        }
    }

    int m;
    std::cin >> m;

    // Переход на следующую строку
    std::cin.ignore();

    std::vector<int> queryResults;

    for (int i = 0; i < m; i++) {
        std::string queryLogin;
        std::cin >> queryLogin;

        if (userBalances.find(queryLogin) != userBalances.end()) {
            queryResults.push_back(userBalances[queryLogin]);
        } else {
            queryResults.push_back(0);
        }
    }

    for (int i = 0; i < queryResults.size(); i++) {
        std::cout << queryResults[i] << " ";
    }

    return 0;
}
