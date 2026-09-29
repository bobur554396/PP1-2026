#include <iostream>

using namespace std;

int main(){
    // - [ ] Show negative elements from given int array
    /*
    Input:
    4
    3 -1 -6 2

    Output:
    -1 -6 
    */
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            cout << a[i] << " ";
        }
    }
    cout << endl;

    
    


    return 0;
}