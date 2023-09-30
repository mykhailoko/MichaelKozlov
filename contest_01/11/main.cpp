#include <iostream>
using namespace std;

int main() {
    double A, B, C;
    int result1;
    int result2;
    int result3;

    cin >> A >> B >> C;
    
    if (A > B) {
        result1 = A-B;
    } else if (B > A) {
        result1 = B-A;
    }

    if (A > C) {
        result2 = A-C;
    } else if (C > A) {
        result2 = C-A;
    }

    if (result1 > result2) {
        cout << "C " << result2 << endl;
    } else if (result2 > result1) {
        cout << "B " << result1 << endl;
    }

}

