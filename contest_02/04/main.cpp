#include <iostream>
#include <tuple>

int gcd(int a, int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

std::tuple<int, int> reduce(int m, int n) {
    int common_divisor = gcd(m, n);
    if (n < 0) {
        common_divisor = -common_divisor;
    }
    m /= common_divisor;
    n /= common_divisor;
    return std::make_tuple(m, n);
}

std::tuple<int, int, int> find_lcm(int a, int b) {
    int common_divisor = gcd(a, b);
    int lcm = a * (b / common_divisor);
    int c = lcm / a;
    int d = lcm / b;
    return std::make_tuple(lcm, c, d);
}

int main() {
    int m1, n1, m2, n2;
    char _;
    std::cin >> m1 >> _ >> n1
             >> m2 >> _ >> n2;
    std::tie(m1, n1) = reduce(m1, n1);
    std::tie(m2, n2) = reduce(m2, n2);

    auto[lcm, c1, c2] = find_lcm(n1, n2);
    auto[m, n] = reduce(m1 * c1 + m2 * c2, lcm);

    std::cout << m << '/' << n << std::endl;
}

