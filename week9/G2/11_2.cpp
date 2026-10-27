#include <iostream>

using namespace std;

double myPow(int base, int exp){
    // 2^-3 = 1 / 2^3 = 1 / 8 = 0.125
    double res = 1;
    if(exp >= 0){
        for(int i = 0; i < exp; i++){
            res *= base;
        }
        return res;
    } else {
        for(int i = 0; i < abs(exp); i++){
            res *= base;
        }
        // cout << res << endl;
        return 1 / res;
    }
}

int main() {
    
    cout << myPow(2, -3) << endl;


    return 0;
}
