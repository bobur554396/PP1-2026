#include <iostream>
#include <bitset>

using namespace std;

int main(){
    // - [ ] set 1 for i-th bit of number
    int n = 5;
    // n = 5 => 0101
    int i = 1;
    /*
    5 => 0101
    i = 1
    ----------

    1 << i => 0010

    0101
    |
    0010
    0111
    */
    int b = 1 << i;

    cout << (n | b) << endl;




    return 0;
}