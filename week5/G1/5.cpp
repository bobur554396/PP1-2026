#include <iostream>

using namespace std;

int main(){
    // - [ ] Sum of all elements int array
    /*
    Input:
    4
    3 1 0 2

    Output:
    6
    */
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i]; // sum = sum + a[i];
    }

    cout << sum << endl;
    
    


    return 0;
}