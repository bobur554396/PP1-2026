#include <iostream>

using namespace std;

int main() {
    int N = 5;
    int arr[N]; // empty array of size N

    int* p = arr; // same as &arr[0]

    for(int i = 0; i < N; i++) {
        *(p + i) = i * 10;
        // arr[i] = i * 10; // same as *(p + i)
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}