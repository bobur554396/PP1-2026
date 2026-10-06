#include <iostream>

using namespace std;

int main() {
    // 2D array (matrix), declaration, MAXN
    // data_type array_name[row_size][column_size];
    
    int c[] = {1, 2, 3};

    int a[3][4]; // declare the 2D array
    
    a[0][0] = 5; // storing the value;
    a[1][2] = 7;
    // a[3][0] = 3; error out of range

    int b[3][4] = {
        {5, 8, 2, 9},
        {1, 0, 7, 4},
        {3, 6, 8, 2},
    };

    // cout << b[1][3] << endl;
    // cout << b[2][1] << endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            // cout << i << j << " ";
            cout << b[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}