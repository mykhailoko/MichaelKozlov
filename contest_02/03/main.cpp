#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int count_ones(const std::string& num) {
    return std::count(num.begin(), num.end(), '1');
}

bool compare(const std::string& num1, const std::string& num2) {
    int ones1 = count_ones(num1);
    int ones2 = count_ones(num2);

    if (ones1 != ones2) {
        return ones1 > ones2;
    } else {
        return std::stoi(num1, 0, 2) < std::stoi(num2, 0, 2);
    }
}

int main(){
    int count;
    std::cin >> count;
    
    std::vector<std::string> nums(count);
    for(auto& line : nums) std::cin >> line;
    
    std::sort(nums.begin(), nums.end(), compare);
    
    for(auto& line : nums) std::cout << line << ' ';
}

