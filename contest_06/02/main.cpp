#include<iostream>
#include<string>
#include<map>

std::map<std::string, double> bonuses;

class Employee {
protected:
    std::string name;
    std::string position;
    int salary;

public:
    Employee(std::string name, std::string position, int salary)
        : name(name), position(position), salary(salary) {}

    virtual int bonus(double percent) const {
        return static_cast<int>(salary * percent + 0.5);
    }

    friend std::ostream& operator<<(std::ostream& os, const Employee& e) {
        os << e.name << " (" << e.position << "): " << e.salary + e.bonus(bonuses[e.position]);
        return os;
    }
};

class Manager : public Employee {
public:
    Manager(std::string name, int salary = 16242)
        : Employee(name, "manager", salary) {}

    int bonus(double percent) const override {
        percent = std::max(percent, 0.1);
        return static_cast<int>(salary * percent + 0.5);
    }
};

class Boss: public Employee{
public:
    Boss(std::string name, int money = 16242)
    :Employee(name, "boss", money){
    }
};

int main(){
    double boss_bonus, manager_bonus;
    std::cin >> boss_bonus >> manager_bonus;
    bonuses["manager"] = manager_bonus;
    bonuses["boss"] = boss_bonus;

    int john_money, bob_money, alice_money;
    std::cin >> john_money >> bob_money >> alice_money;
    Boss john("John", john_money);
    Manager bob("Bob", bob_money);
    Manager alice("Alice", alice_money);

    std::cout << john << '\n' << bob << '\n' << alice << std::endl;
}
