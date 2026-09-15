#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int a = 3;
    // 0011 = 1 * 2^0 + 1 * 2^1 + 0 * 2^2 + 0 * 2^3 = 3
    /*
    3 = 0011
    ~3 = 1100 => 4 + 8 = 12 - wrong
    */
    int b = ~a;

    /*
    
    ~N = -N - 1
    -N = ~N + 1

    ~3 = -3 - 1 = -4
    ~0 = -0 - 1 = -1


    // assume
    ~N = -N
    ~3 = -3
    ~2 = -2
    ~1 = -1
    ~0 = -0 -- key point, why we are getting - 1 in formula


    one's complement (~N) 
    two's complement (~N + 1)
    */
    
    bitset<32> b1(a);
    bitset<32> b2(b);

    cout << b1 << endl << b2 << endl;

    cout << b << endl;


    return 0;
}