#include <iostream>

using namespace std;

int main(){
    // - [ ] Find max from given array
    /*
    Input:
    4
    3 6 8 2

    Output:
    8
    */
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // int max = -99999;
    int max = a[0]; // assume that first element of an array is max
    for(int i = 0; i < n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }

    cout << max << endl;
    

    
    


    return 0;
}