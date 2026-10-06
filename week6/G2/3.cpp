#include <iostream>

using namespace std;

int main() {
    // Multiplication table
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){ // outer
        // cout << "i = " << i << endl;
        for(int j = 1; j <= n; j++){ // inner
            cout.width(3);
            cout << i * j << " ";
        }
        cout << endl;
    }
    cout << endl;



    return 0;
}