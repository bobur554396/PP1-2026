#include <iostream>

using namespace std;

int main() {
    /*
    Your are given, N and M, rows and columns table.
    Input:
    3 4 
    5 8 2 9
    1 0 7 4 
    3 6 8 2

    Output:
    5 8 2 9 
    1 0 7 4 
    3 6 8 2
    */

    // freopen(file_path, mode, stream) -- redirect the input/output stream to file
    // "r" - read, "w" - write
    // stdin - standard input stream
    // stdout - standard output stream
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 

    // 1. Reading part.
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
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