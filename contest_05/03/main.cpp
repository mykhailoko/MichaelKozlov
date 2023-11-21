#include <iostream>
#include <string>

#include <complex.h>
#include <complex>
#include <sstream>
using namespace std;


class Complex {
public:
    Complex(string input) {
        double re, im;
        stringstream ss(input);
        ss >> re;

        string im_str;
        ss >> im_str;
        if (im_str.length() == 1) {
            string temp;
            ss >> temp;
            im_str += temp;
        }

        im = stod(im_str);

        if (re == -0) re = 0;
        if (im == -0) im = 0;

        num = complex <double>(re, im);
    }
     
    Complex(complex<double> init_num) {
        num = init_num;
    }

    double re() const {
        return num.real();
    }
    double im() const {
        return num.imag();
    }

    Complex operator+(const Complex& b) {
        return Complex(num + b.num);
    }
    Complex operator-(const Complex& b) {
        return Complex(num - b.num);
    }
    Complex operator*(const Complex& b) {
        return Complex(num * b.num);
    }
    Complex operator/(const Complex& b) {
        return Complex(num / b.num);
    }

    friend ostream& operator<<(ostream& out, const Complex& num) {
        double re = num.re();
        double im = num.im();
        out << (re == 0.0 ? 0.0 : re)
            << (im < 0 ? "" : "+")
            << (im == 0.0 ? 0.0 : im) << 'j';
        return out;
    }

private:
    complex<double> num;
};

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1(num);

    std::getline(std::cin, num, 'j');
    Complex c2(num);

    std::cout << c1 + c2 << '\n' << c1 - c2 << '\n'
        << c1 * c2 << '\n' << c1 / c2 << std::endl;
}
