#include <iostream>
#include <deque>

class Water {
private:
    int temperature;

public:
    Water(int initial_temperature) : temperature(initial_temperature) {}

    int get_temperature() const {
        return temperature;
    }

    void heat_up(int degrees) {
        if (temperature < 100) {
            temperature += degrees;
            if (temperature >= 100) {
                temperature = 100;
            }
        }
    }
};

class Teapot {
private:
    Water& water;

public:
    Teapot(Water& w) : water(w) {}

    bool is_boiling() const {
        return water.get_temperature() == 100;
    }

    void heat_up(int degrees) {
        if (!is_boiling()) {
            water.heat_up(degrees);
        }
    }
};

int main()
{
    int temperature, count;
    std::cin >> temperature >> count;
    std::deque<int> heat(count);
    for(auto& t : heat) std::cin >> t;
    
    Water water(temperature);
    Teapot teapot(water);
    
    while(not teapot.is_boiling()){
        teapot.heat_up(heat.front());
        heat.pop_front();
    }
    
    for(auto t : heat) std::cout << t << ' ';
}
