#include <iostream>
#include <cmath>

bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number == 2) {
        return true;
    }

    if (number % 2 == 0) {
        return false;
    }

    int sqrt_number = static_cast<int>(std::sqrt(number));
    for (int i = 3; i <= sqrt_number; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;
}

