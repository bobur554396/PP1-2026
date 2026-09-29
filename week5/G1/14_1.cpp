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

    bool flag = false;
    for(int i = 0; i < n; i++){
        if(a[i] == k){
            cout << "YES" << endl;
            flag = true;
            break;
        }
    }
    if(flag == false)// if(!flag)
        cout << "NO" << endl;
    

    
    


    return 0;
}