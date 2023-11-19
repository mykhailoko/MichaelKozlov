#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& text) {
    std::stack<char> stack;

    for (char c : text) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (stack.empty()) {
                return false; // Закрывающая скобка без соответствующей открывающей
            }
            char openBracket = stack.top();
            stack.pop();
            if ((c == ')' && openBracket != '(') ||
                (c == '}' && openBracket != '{') ||
                (c == ']' && openBracket != '[')) {
                return false; // Несоответствие открывающей и закрывающей скобок
            }
        }
    }

    return stack.empty(); // Если стек пуст, то скобки сбалансированы
}

int main() {
    std::string input;
    std::getline(std::cin, input, '!');

    if (isBalanced(input)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

