#include <iostream>

using namespace std;

int main(){
    /*
    Input:
    4
    3 1 0 2

    Output:
    3 1 0 2
    */

    // 1. Reading part
    int n;
    // int a[n]; // error
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
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