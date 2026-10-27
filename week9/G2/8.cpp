#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int global = 100; // Global variable

void hello(){
    cout << global << " inside hello function" << endl;
    cout << "Hello KBTU" << endl;
}

int sum(int a, int b){
    int res = a + b; // local variable
    return res + global;
}

int main() {
    hello(); // () - calling the function

    // cout << res << endl; // error
    
    int r = sum(2, 3); // local variable in main function
    // cout << r << endl;
    cout << sum(2, 3) << endl;

    cout << global << " inside main function" << endl;

    return 0;
}