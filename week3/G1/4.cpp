#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int a = 5;
    /*
    5 = 0101
    */
    int b = ~(a);
    /*
    5  = 0101
    ~5 = 1010 => 10
    */
    bitset<32> b1(a);
    bitset<32> b2(b);

    /*
    -0 = ~0 => error, therefore was added + 1


    -N = ~N + 1
    ~X = -X - 1;

    ~5 = -5 - 1 = -6;


    -6 = 11111111111111111111111111111010
         00000000000000000000000000000101  
    
    read at home:

    one's complement (~N)
    two's complement (~N + 1)
    */

    cout << "a = 5: " << b1 << endl;
    cout << "~(a): " << b2 << endl;
    cout << b << endl;

    return 0;
}