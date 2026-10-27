#include <iostream>

using namespace std;

int max(double a, double b) {
    if(a > b) 
        return a;
    // else
    return b;
}

int main() {
    
    cout << max(10, 20) << endl;  // 20

    return 0;
}