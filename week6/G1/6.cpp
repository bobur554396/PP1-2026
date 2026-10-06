#include <iostream>

using namespace std;

int main(){
    /*
    Your are give number N and M, rows and columns of 2d array. Then you are given N rows of M integers. You have to print the 2d array.
    Input:
    3 3
    3 1 2
    4 5 9
    3 7 2

    Output:
    3 1 2
    4 5 9
    3 7 2
    */

    // 1. Reading part.
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j]; // a[0][3] -- out of bounds
        }
    }

    // 2. Solution part.
    // ...

    // 3. Printing part.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }    




    

    return 0;
}