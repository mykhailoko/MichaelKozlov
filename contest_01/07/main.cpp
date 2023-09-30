#include <iostream>
using namespace std;

int main() {
    double num1, num2;

    cin >> num1 >> num2;

    if (num1 > num2) {
        cout << num1 << endl;
    } else if (num2 > num1) {
        cout << num2 << endl;
    } else {
    	cout << num1 << "=" << num2 << endl;
    }

}

