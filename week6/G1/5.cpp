#include <iostream>

using namespace std;

int main(){
    // 2D Array (Matrix)

    int aa[5] = {1, 2, 3, 4, 5}; // declaration of 1D array

    // data_type array_name[row_size][column_size];
    int a[3][4]; // declaration of 2D array

    a[0][0] = 5; // assignment of value to 2D array
    a[0][1] = 2;

    int b[3][4] = { // declaration and initialization of 2D array
        {5, 2, 9, 1},
        {7, 3, 8, 4},
        {6, 0, 2, 5}
    };

    // cout << *(*b) << endl;
    // cout << b[1][2] << endl;
    // cout << b[2][1] << endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            // cout << i << " " << j << endl;
            cout << b[i][j] << " ";
        }
        cout << endl;
    }


    

    return 0;
}