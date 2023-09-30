#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int cur = 0;
    int len = 1;
    int max = 2;
    int ln_step = 1;

    for (int i = 1; i <= n; i++){
        std::cout << i << ' ';

        cur++;
        if (cur == len){
            std::cout << std::endl;
            len += ln_step;
            cur = 0;
        }

        if (len == max || len == 1){
            ln_step *= -1;
        }
        if (len == max) max++;
    }
    return 0;
}
