#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[5] = {5, 2, 9, 1, 7};

    // cout << a << endl;

    sort(a, a + 5); // sort([start_address, end_address))
    reverse(a, a + 5); // reverse([start_address, end_address))

    for(int i = 0; i < 5; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    

    return 0;
}