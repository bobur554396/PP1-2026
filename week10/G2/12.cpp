#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    // int a[n];
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        // cin >> v[i];
    }

    // solution part

    
    int size = v.size();                // int copy: no signed/unsigned warning
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}