#include <iostream>

using namespace std;

int main(){
    // sum (<number> * base ^ <position>)
    int a = 3;
    /*
    dec(3) = bin(0011) = 1 * 2^0 + 1 * 2^1 + 0 * 2^2 + 0 * 2^3 = 3

    int - 4 byte = 32 bit
    3 = 0000 0000 0000 0000 0000 0000 0000 0011
    */
    int b = 5;
    /*
    5 = 0000 0000 0000 0000 0000 0000 0000 0101
    */

    int c = a ^ b;
    /*
    3 = 0011
    ^
    5 = 0101
    --------
        0110 => 2 + 4 = 6
    */

    cout << c << endl;

    // int d = 2 ^ 7;
    // int d = 0x2 ^ 7;
    int d = 2 xor 7;
    // int d = 3 ^ 7;
    /*
    2 = 0010
    ^
    7 = 0111
    --------
        0101 => 1 + 4 = 5
    */

    cout << d << endl;



    return 0;
}