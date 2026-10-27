#include <iostream>

using namespace std;

int global = 100;  // Global variable

void demo() {
    // cout << a << endl;
    int local = 5;  // Local to function
    cout << "Local: " << local << endl;
    cout << "Global: " << global << endl;
}

int main() {
    int a = 10; // local in main function;
    demo();
    cout << "Global in main: " << global << endl;
    // cout << local;  // Error! local is not accessible
    return 0;
}