#include <iostream>
#include <bitset>

using namespace std;

int main(){
    // your are given number N, return 2^N; 
    // - don't use function pow from cmath, 
    // - don't use loop
    int n;
    cin >> n;
    /*
    n = 0; 1 => 0001
    n = 1; 2 => 0010
    n = 2; 4 => 0100
    n = 3; 8 => 1000

    1 << 0 => 0001
    1 << 1 => 0010
    1 << 2 => 0100
    1 << 3 => 1000
    */
    cout << (1 << n) << endl;



    return 0;
}