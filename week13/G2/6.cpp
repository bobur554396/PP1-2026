#include <iostream>

using namespace std;

int main() {
    int arr[4] = {10, 20, 30, 40};

    // 1. pointer arithmetic with an index
    int* p = arr;
    for (int i = 0; i < 4; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;

    // 2. moving the pointer itself
    p = arr;                       // put it back to the start
    while (p < arr + 4) {
        cout << *p << " ";
        p++;                       // advance by one element
    }
    cout << endl;

    // 3. the same with a for loop
    // for(vector<int>::iterator it = arr; it != arr + 4; ++it) {
    //     cout << *it << " ";
    // }
    for (int* q = arr; q != arr + 4; q++) {
        cout << *q << " ";
    }
    cout << endl;
    return 0;
}