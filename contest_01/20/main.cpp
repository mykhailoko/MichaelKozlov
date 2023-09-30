#include <iostream>
#include <algorithm>

int main() {
    std::string a, b;
    std::cin >> a >> b;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    if (a==b) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}

