#include <iostream>
#include <cstring>

class Keeper {
    int trash;
    int secret;

public:
    Keeper() {
        std::cin >> secret;
    }
};

struct Hack {
    int trash;
    int secret;
};

int hack_it(Keeper keeper) {
    Hack h;
    std::memcpy(&h, &keeper, sizeof(Keeper));
    return h.secret;
}

int main() {
    Keeper keeper;
    int secret = hack_it(keeper);
    std::cout << secret;
}

