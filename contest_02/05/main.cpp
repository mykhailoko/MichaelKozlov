
#include <iostream>

struct Complex{
  double re;  // Действительная часть
  double im;  // Мнимая часть
};

// Функция для создания комплексного числа из строки
Complex make_complex(const std::string& str) {
    Complex result;
    std::istringstream iss(str);
    char plus_minus;
    iss >> result.re >> plus_minus >> result.im;
    if (plus_minus == '-') {
        iss >> plus_minus;
        result.im = -result.im;
    }
    return result;
}

// Функция для вывода комплексного числа
void print(const Complex& c) {
    std::cout << c.re << (c.im >= 0 ? '+' : '-') << std::abs(c.im) << 'j' << std::endl;
}

// Функция для сложения двух комплексных чисел
Complex sum(const Complex& a, const Complex& b) {
    Complex result;
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result;
}

// Функция для вычитания двух комплексных чисел
Complex sub(const Complex& a, const Complex& b) {
    Complex result;
    result.re = a.re - b.re;
    result.im = a.im - b.im;
    return result;
}

// Функция для умножения двух комплексных чисел
Complex mul(const Complex& a, const Complex& b) {
    Complex result;
    result.re = a.re * b.re - a.im * b.im;
    result.im = a.re * b.im + a.im * b.re;
    return result;
}

// Функция для деления двух комплексных чисел
Complex div(const Complex& a, const Complex& b) {
    Complex result;
    double denominator = b.re * b.re + b.im * b.im;
    result.re = (a.re * b.re + a.im * b.im) / denominator;
    result.im = (a.im * b.re - a.re * b.im) / denominator;
    return result;
}

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1 = make_complex(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2 = make_complex(num);
    
    print(sum(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));
}
