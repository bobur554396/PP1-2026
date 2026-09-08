#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    // - [ ] factorial
    /*
    in: 4
    out: 4! = 1 * 2 * 3 * 4 = 24
    */
    int n;
    cin >> n;

    /*
    1) res = 1
    2) res = res * 1 = 1
    3) res = res * 2 = 2
    4) res = res * 3 = 6
    5) res = res * 4 = 24
    */
    int res = 1;
    for(int i = 1; i <= n; i++){
        // cout << i << " ";
        res *= i; // res = res * i;
    }
    cout << res << endl;


    
    

    return 0;
}