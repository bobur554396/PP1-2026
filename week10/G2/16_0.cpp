#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x;
    vector<int> v;
    
    while (;;) {
        cin >> x;
        if (x == 0) 
            break;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    for (int y : v) 
        cout << y << " ";
    cout << endl;
    return 0;
}