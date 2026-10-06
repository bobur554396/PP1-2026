#include <iostream>

using namespace std;

int main(){
    // 2.3 Multiplication table

    for(int i = 1; i <= 9; i++){ // outer loop

        for(int j = 1; j <= 9; j++){ // inner loop
            // cout << "i = " << i << ", j = " << j << endl;
            cout.width(3); // set width of output
            cout << i * j << " ";
        }
        cout << endl;

    }
    cout << endl;
    

    return 0;
}