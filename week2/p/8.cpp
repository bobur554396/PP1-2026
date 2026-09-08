#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    // - [ ] all numbers which divisible by N in range (a, b)
    /*
    a b n

    in: 2 13 3
    out: 3 6 9 12
    */
    int a, b, n;
    cin >> a >> b >> n;

    for(int i = a; i <= b; i++){
        // cout << i << " ";
        if(i % n == 0){
            cout << i << " ";
        }
    }



    return 0;
}