#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int a[4] = {4, 5, 1, 2};

    // sort([start_address, end_address))
    sort(a, a + 4);           // ascending
    reverse(a, a + 4); // reverse([start_address, end_address))
    
    for (int i = 0; i < 4; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


    return 0;
}