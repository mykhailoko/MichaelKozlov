#include <iostream>

int main() {
    std::string input;
    std::cin >> input;

    input.append ("a");

    char lastChar = input[0];
    int repeatLength = 1;
    for (int i = 1; i < input.length(); i++) {
        if (input[i] == lastChar) {
            repeatLength++;
            continue;
        }

        if (input[i] != lastChar) {
            std::cout << lastChar;
            if (repeatLength > 1)
                std::cout << repeatLength;

            lastChar = input[i];
            repeatLength = 1;
        }
    }

    return 0;
}
