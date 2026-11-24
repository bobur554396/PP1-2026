#include <iostream>

using namespace std;

int main() {
    int a[4] = {10, 20, 30, 40};


    cout << (a == &a[0]) << endl;     // 1: the array name is the address of element 0
    cout << *a << endl;               // 10, the same as a[0]
    cout << a[0] << endl;         // 30, the same as a[2]
    cout << *(a + 2) << endl;         // 30, the same as a[2]
    cout << a[2] << endl;             // 30

    return 0;
}