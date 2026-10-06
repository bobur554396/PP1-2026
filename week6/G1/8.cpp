#include <iostream>

using namespace std;

int main(){
    /*
    Max element in matrix
    Input:
    3 3
    3 1 2
    4 5 9
    3 7 2

    Output:
    9
    */

    freopen("input.txt", "r", stdin); // stdin - standard input, r = read

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int max = a[0][0]; // assume the first element is the max
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] > max){
                max = a[i][j];
            }        
        }
    }

    cout << max << endl;




    

    return 0;
}