#include <iostream>

using namespace std;

int main(){
    //    - [ ] Show even numbers from given array
    /*
    Input:
    4
    2 5 3 6

    Output:
    2 6
    */
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            cout << a[i] << " ";
        }
    }
    cout << endl;


    



    return 0;
}