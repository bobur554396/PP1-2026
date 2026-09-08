#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    // - [ ] sum of digits of N (always 3 digit numbers will be given)
    /*
    in: 123
    out: 1 + 2 + 3 = 6
    */

    int n;
    cin >> n;

    int n1 = n / 100; 
    int n2 = n % 100 / 10;
    int n3 = n % 10;

    // cout << n1 << " " << n2 << " " << n3 << endl;
    cout << n1 + n2 + n3 << endl;


    
    
    

    return 0;
}