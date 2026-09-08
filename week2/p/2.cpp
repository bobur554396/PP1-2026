#include <iostream>

using namespace std;

int main(){
    // - [ ] (++, --, +=, -=, *=, /=, %= )
    // Post/Pre increment and decrement operators

    int a = 5;
    a++;
    ++a;
    // int b = a++;
    int b = ++a;

    cout << a << " " << b << endl;

    return 0;
}