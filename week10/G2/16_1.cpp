#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    int x;
    cin >> x;
    while (x != 0) {
        v.push_back(x);
        cin >> x;
    }

    sort(v.begin(), v.end());
    for (int y : v) 
        cout << y << " ";
    cout << endl;
    return 0;
}