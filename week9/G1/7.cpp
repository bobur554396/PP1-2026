#include <iostream>
#include <cmath>

using namespace std;

void hello() {
    cout << "Hello, World!" << endl;
}

int sum(int a, int b) {
    int res = a + b;
    return res;
}

int main() {
    
    hello(); // () -> calling the function

    // cout << sum(2, 3) << endl; // 5
    int r = sum(2, 3); // r = 5;
    cout << r << endl;

    return 0;
}