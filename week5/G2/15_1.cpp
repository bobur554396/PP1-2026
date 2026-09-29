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

    bool found = false;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == k){
            cout << "YES" << endl;
            found = true;
            cnt = 1;
            break;
        }
    }
    if(found == false)
        cout << "NO" << endl;
    // if(cnt == 0)
    //     cout << "NO" << endl;


    
    


    



    return 0;
}