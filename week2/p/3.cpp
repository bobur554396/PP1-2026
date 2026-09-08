#include <iostream>

using namespace std;

int main(){
    // - [ ] (++, --, +=, -=, *=, /=, %= )
    // Post/Pre increment and decrement operators

    int a = 5;
    int b = 2;
    int c = 7;

    int res = a++ + ++b - c++;

    cout << res << endl;

    return 0;
}