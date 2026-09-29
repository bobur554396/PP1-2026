#include <iostream>

using namespace std;

int main(){
    //  - [] Read N number and show them
    /*
    Input:
    4
    3 2 1 5

    Output:
    3 2 1 5
    */

    // 1. Reading part
    int n;
    // int a[n]; // error
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){ // [0...n-1]
        cin >> a[i];
    }

    // 2. Solution part
    // ...


    // 3. Output part
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    



    return 0;
}