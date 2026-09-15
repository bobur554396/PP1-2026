#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int n;
    cin >> n;
    // 2 ^ n - don't use function pow from cmath pow(2, n); don't use loops

    /* 
    n = 0; 1 => 0001
    n = 1; 2 => 0010
    n = 2; 4 => 0100
    n = 3; 8 => 1000

    1 << N;
    */
    cout << (1 << n) << endl;

    return 0;
}