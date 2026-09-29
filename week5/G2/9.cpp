#include <iostream>

using namespace std;

int main(){
    // - [ ] Show numbers in odd index/position from given array
    /*
    Input:
                4
                2 5 3 6
    position:   0 1 2 3
    Output:
    5 6
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