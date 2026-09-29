#include <iostream>

using namespace std;

int main(){
    // - [ ] Linear search of K from given array
    /*
    Input:
    4 
    3 6 8 2
    8

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

    bool flag = false; // assume that number K is not exists in the given array 
    for(int i = 0; i < n; i++){
        if(a[i] == k){
            flag = true; // I found number K in the array
        }
    }
    // "flag" will be true/false
    // true - if K exists in the given array
    // false - if K not exists, "if" block is not executed
    if(flag == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    
    


    return 0;
}