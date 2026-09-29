#include <iostream>

using namespace std;

int main(){
    // - [ ] Linear search of K from given array
    /*
    Input:
    4
    2 5 6 3
    6
    
    Output:
    YES
    */
    int n, k;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;

    for(int i = 0; i < n; i++){
        if(a[i] == k){
            cout << "YES" << endl;
            return 0; // manually stop the program here
        }
    }
    cout << "NO" << endl;


    return 0;
}