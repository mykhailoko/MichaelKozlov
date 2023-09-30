#include <iostream>
#include <string>

std::string getExcelColumnName(int N) {
    std::string result = "";

    while (N != 0) {
        N -= 1;
        char c = (N % 26) + 'A';
        result = c + result;
        N /= 26;
    }

    return result;
}

int main() {
    int N;
    std::cin >> N;

    std::string columnName = getExcelColumnName(N);
    std::cout << columnName << std::endl;

    return 0;
}

