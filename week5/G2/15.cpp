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

    bool flag = false; // assume that number K is not exists in the array
    for(int i = 0; i < n; i++){
        if(a[i] == k){
            flag = true;
        }
    }
    if(flag == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    
    


    



    return 0;
}