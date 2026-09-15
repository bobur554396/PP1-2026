#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int n;
    cin >> n;
    // is it power of 2

    /* 
    i = 0; 1 => 0001
    i = 1; 2 => 0010
    i = 2; 4 => 0100
    i = 3; 8 => 1000

    


    n = 4
    0100

    n = 3
    0011
    ----
    0000 = 0


    n = 6
    0110

    n = 5
    0101
    ----
    0100 


    n = 10
    1010

    n = 9
    1001
    ----
    1000


    n = 8
    1000
    n = 7
    0111
    ----
    0000 = 0

    */
    if((n & (n - 1)) == 0)
        cout << "YES"  << endl;
    else
        cout << "NO" << endl;

    return 0;
}