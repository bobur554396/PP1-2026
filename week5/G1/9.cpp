#include <iostream>

using namespace std;

int main(){
    // - [ ] Show elements in odd position from given array
    /*
    Input:
         4
         3 8 6 2
    pos: 0 1 2 3

    Output:
    8 2 
    */
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        if(i % 2 != 0){
            cout << a[i] << " ";
        }
    }
    cout << endl;

    
    


    return 0;
}