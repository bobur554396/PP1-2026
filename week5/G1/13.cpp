#include <iostream>

using namespace std;

int main(){
    // - [ ] Find min from given array
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

    // int min = 99999;
    int min = a[0]; // assume that first element of an array is min
    for(int i = 0; i < n; i++){
        if(a[i] < min){
            min = a[i];
        }
    }

    cout << min << endl;
    

    
    


    return 0;
}