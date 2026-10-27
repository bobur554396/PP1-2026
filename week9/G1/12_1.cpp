#include <iostream>

using namespace std;


int myPow(int base, int exp){
    // 2^3 = 1 * 2 * 2 * 2
    int res = 1;
    /*
    1) res = 1; res = 1 * 2 = 2
    2) res = 2; res = 2 * 2 = 4
    3) res = 4; res = 4 * 2 = 8
    */
    for(int i = 0; i < exp; i++){
        res *= base;
    }
    return res;
}


int main() {
    
    cout << myPow(2, 0) << endl;

    return 0;
}