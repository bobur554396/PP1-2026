#include <iostream>

using namespace std;

void printArray(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";        // same as *(arr + i)
    }
    cout << endl;
}

int main() {
    int a[4] = {1, 2, 3, 4};
    printArray(a, 4);                 // the array is passed as an address
    return 0;
}