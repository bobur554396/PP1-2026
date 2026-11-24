#include <iostream>

using namespace std;

int main() {
    int x = 10;
    int* ptr = &x;        // ptr holds the address of x

    cout << "Value of x: " << x << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;

    *ptr = 50;            // change x through the pointer
    cout << "New x: " << x << endl;

    cout << "Same address: " << (ptr == &x) << endl;
    return 0;
}