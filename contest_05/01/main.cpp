#include <iostream>
#include <cstdlib>
#include <ctime>

class Cat {
    public:
        Cat(bool isAlive) : alive(isAlive) {}

        bool is_alive() const {
            return alive;
        }
        
    private:
        bool alive;
};

class Box {
    public:
        Cat open() {
            bool isAlive = (rand() % 2) == 0;

            Cat cat(isAlive);

            return cat;
        }
};

int func() {
    srand(time(0));

    Box box;
    Cat cat = box.open();

    if (cat.is_alive()) {
        std::cout << "alive";
    } else {
        std::cout << "dead";
    } 

    return 0;
 }
