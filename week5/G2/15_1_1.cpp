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

    string res = "not found";
    for(int i = 0; i < n; i++){
        if(a[i] == k){
            cout << "YES" << endl;
            res = "found";
            break;
        }
    }
    if(res == "not found")
        cout << "NO" << endl;

    
    


    



    return 0;
}