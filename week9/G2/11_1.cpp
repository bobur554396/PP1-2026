#include <iostream>

using namespace std;

int myPow(int base, int exp){
    // 2^3 = 1 * 2 * 2 * 2 = 8
    int res = 1;
    for(int i = 0; i < exp; i++){
        // res = res * base;
        res *= base;
    }
    return res;
}

int main() {
    
    cout << myPow(2, 3) << endl;


    return 0;
}
