#include <iostream>

using namespace std;

int main(){
    /*
    Symmetric with bool
    Input:
    3
    2 3 1
    4 5 8
    3 8 3

    Output:
    YES

    00 01 02
    10 11 12
    20 21 22
    */

    freopen("input.txt", "r", stdin); // stdin - standard input, r = read

    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != a[j][i]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    

    return 0;
}