#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {5, 3, 8, 1};
    int n = 4;

    sort(arr, arr + n);           // Sort ascending
    for (int i = 0; i < n; i++) cout << arr[i] << " ";  // 1 3 5 8
    cout << endl;

    reverse(arr, arr + n);        // Reverse array
    for (int i = 0; i < n; i++) cout << arr[i] << " ";  // 8 5 3 1
    cout << endl;

    return 0;
}