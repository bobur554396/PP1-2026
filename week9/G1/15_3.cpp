#include <iostream>

using namespace std;

// implement the function - isPrime
/*
prime numbers - 1, 3, 5, 7, 11, 17, 23, 51 ...
*/

bool isPrime(int n){
    int cnt = 0;
    for(int i = 2; i <= sqrt(n/2); i++){
        if(n % i == 0)
            cnt++;
    }
    if(cnt == 0)
        return true;
    return false;
}


int main() {
    int n;
    cin >> n;

    if(isPrime(n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}