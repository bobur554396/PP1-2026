#include <iostream>
#include <bitset>

using namespace std;

int main(){
    // - [ ] invert i-th bit of number: 
    int n, i;
    cin >> n >> i;    
    /*
    5 => 0101
    i = 0
    ----------

    1 << i => 0010

    0101
    ^
    0001
    ----
    0100 => 4


    0101
    ^
    0010
    ----
    0111 => 7
    */
    int b = 1 << i;

    cout << (n ^ b) << endl;




    return 0;
}