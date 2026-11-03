#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a[] = {10, 20, 30};
    vector<int> v(a, a + 3); // copy the array into the vector

    int size = v.size();                // int copy: no signed/unsigned warning
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;    
    return 0;
}