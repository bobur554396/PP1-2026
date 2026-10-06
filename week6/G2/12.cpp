#include <iostream>

using namespace std;

int main() {
    // Opposite eye (1, 2, 3)
    /*
    input:
    3

    output:
    2 2 1
    2 1 3
    1 3 3

    00 01 02
    10 11 12
    20 21 22

    00 01 02 03
    10 11 12 13
    20 21 22 23
    30 31 32 33

    */
    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // implement 
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    

    return 0;
}