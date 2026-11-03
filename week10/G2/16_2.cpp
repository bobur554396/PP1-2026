#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    int x;
    while (cin >> x && x != 0) {
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    for (int y : v) cout << y << " ";
    cout << endl;
    return 0;
}