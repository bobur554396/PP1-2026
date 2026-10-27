#include <iostream>

using namespace std;

// pow from cmath
double myPow(int base, int exp){
    // 2^3 = 2 * 2 * 2 = 8
    // 2^-3 = 1 / 2^3 = 1 / 8 = 0.125 
    double res = 1;
    for(int i = 0; i < abs(exp); i++){
        res *= base;
    }
    if(exp < 0)
        return 1 / res;
    return res; 
}


int main() {
    
    cout << myPow(2, 3) << endl;
    cout << myPow(2, -3) << endl;

    return 0;
}