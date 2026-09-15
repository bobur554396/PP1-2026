#include <iostream>
#include <bitset>

using namespace std;

int main(){
    // - [ ] set 0 for i-th bit of number
    int n, i;
    cin >> n >> i;
    /*
    5 => 0101
    i = 0
    ----------
    i = 0: 0101 => 0100 => 4
    i = 1: 0101 => 0101 => 5
    i = 2: 0101 => 0001 => 1

    1 << i

    ~(0001) => 1110

    0101
    &
    1110
    ----
    0100 => 4


    0101
    &
    1101
    ----
    0101

    */
    int b = ~(1 << i);

    cout << (n & b) << endl;




    return 0;
}