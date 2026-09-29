#include <iostream>

using namespace std;

int main(){
    // - [ ] Find min from given array
    /*
    Input:
    4
    2 5 6 3
    
    Output:
    6
    */
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // int max = -999999;
    int max = a[0]; // assume that first element of the array is max
    for(int i = 0; i < n; i++){
        if(a[i] < max){
            max = a[i];
        }
    }

    cout << max << endl;

    
    


    



    return 0;
}