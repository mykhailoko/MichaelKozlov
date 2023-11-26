#include <iostream>
#include <vector>

class Shape {
public:
    virtual double getPerimeter() const = 0;
    virtual ~Shape() {}  // Виртуальный деструктор для правильного освобождения памяти
};

class Rectangle : public Shape {
private:
    int length;
    int width;

public:
    Rectangle(int a, int b) : length(a), width(b) {}

    double getPerimeter() const override {
        return 2 * (length + width);
    }
};

class Circle : public Shape {
private:
    int radius;
    const double PI = 3.14159265358979323846;  // Значение PI

public:
    Circle(int r) : radius(r) {}

    double getPerimeter() const override {
        return 2 * PI * radius;
    }
};

class Triangle : public Shape {
private:
    int sideA;
    int sideB;
    int sideC;

public:
    Triangle(int a, int b, int c) : sideA(a), sideB(b), sideC(c) {}

    double getPerimeter() const override {
        if (sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA) {
            return sideA + sideB + sideC;
        } else {
            return 0;
        }
    }
};

int main(){
    int momentum;
    std::cin >> momentum;
    srand(momentum);
    std::vector <Shape*> shapes(rand() % 100 + 1);
    for (int i=0; i < shapes.size(); i++){
        int a = rand()%10 + 1, b = rand()%10 + 1, c = rand()%10 + 1;
        if (rand() % 3 == 0) shapes[i] = new Rectangle(a, b);
        else if (rand() % 3 == 1) shapes[i] = new Circle(c);
        else shapes[i] = new Triangle(a, b, c);
    }
    
    double sum = 0;
    for (auto shape : shapes) { sum += shape->getPerimeter();}
    std::cout << (int)sum;
}
