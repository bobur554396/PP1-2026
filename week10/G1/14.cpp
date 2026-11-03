#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// comparator function
bool desc(int a, int b) {
    return a > b;           // "a must come before b"
}

int main() {
    vector<int> v = {5, 2, 8, 1};

    // sort(v.begin(), v.end());             // ascending, the default
    // for (int x : v) 
    //     cout << x << " ";
    // cout << endl;

    sort(v.begin(), v.end(), desc);       // descending, using our function
    
    for (int x : v) 
        cout << x << " ";
    cout << endl;
    return 0;
}