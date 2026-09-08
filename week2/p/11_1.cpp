#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    // - [ ] sum of digits of N
    /*
    in: 123
    out: 1 + 2 + 3 = 6



    12
    123
    1234
    12345


    1) 1234 % 10 = 4; 1234 / 10 = 123
    2) 123 % 10 = 3; 123 / 10 = 12
    3) 12 % 10 = 2; 12 / 10 = 1
    4) 1 % 10 = 1; 1 / 10 = 0
    5) 0 % 10 = 0;
    */

    int n;
    cin >> n; // 123

    int sum = 0;
    while(n > 0){
        int last_digit = n % 10;
        sum += last_digit; // sum = sum + last_digit;
        n = n / 10;
    }

    cout << sum << endl;



    
    
    

    return 0;
}