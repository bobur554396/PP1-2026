#include <iostream>

using namespace std;

bool isPrime(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
/*
5 - 1 2 3 4 5 => 2
6 - 1 2 3 4 5 6 => 4
7 - 1 2 3 4 5 6 7 => 2
*/

int main() {
    // isPrime
    /*
    prime - 1/itself = 1, 2, 3, 5, 7, 11, 13, 17, 23, ...
    not prime - 6, 9, 12, ...
    */
    int n;
    cin >> n;

    if(isPrime(n))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    

    return 0;
}
