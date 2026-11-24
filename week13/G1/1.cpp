#include <iostream>

using namespace std;

int main(){

    int a = 3;
    int* ptr = &a;

    // cout << &a << endl;
    // cout << ptr << endl;
    // cout << &ptr << endl;

    cout << a << endl;
    cout << *ptr << endl;

    return 0;
}