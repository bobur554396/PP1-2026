#include <iostream>
#include <bitset>

using namespace std;

int main(){
    /*
    from any system to decimal = sum (digit * base ^ position)
    */
    int a = 3;
    // 0011 = 1 * 2^0 + 1 * 2^1 + 0 * 2^2 + 0 * 2^3 = 3
    int b = 5;
    // 0101 = 1 + 4 = 5


    int c = a ^ b; // bitwise XOR
    bitset<4> b1(a);
    bitset<4> b2(b);
    bitset<4> b3(c);

    /*
    3 = 0011
    5 = 0101
    --------
        0110 => 2 + 4 = 6
    */
    printf("a = %i;\nb = %i; \n", a, b);
    cout << b1 << endl << "^" << endl << b2 << endl << b3 << endl;
    
    cout << "res (decimal) = " << c << endl;

    return 0;
}