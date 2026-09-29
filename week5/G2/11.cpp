#include <iostream>

using namespace std;

int main(){
    // - [ ] Count number of positive elements in array
    /*
    Input:
    4
    2 5 -3 6
    
    Output:
    3

    */
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            cnt++;
        }
    }
    cout << cnt << endl;
    


    



    return 0;
}