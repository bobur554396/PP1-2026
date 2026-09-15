#include <iostream>

using namespace std;

int main(){
    /*
    from any system to decimal = sum (digit * base ^ position)
    */
    int a = 3;
    // 0011 = 1 * 2^0 + 1 * 2^1 + 0 * 2^2 + 0 * 2^3 = 3
    int b = 5;
    // 0101 = 1 + 4 = 5

    int c = 7;
    // 1 + 2 + 4 = 7 => 0111

    int d = 13;
    // 8 + 4 + 1 => 1101 = 13

    return 0;
}