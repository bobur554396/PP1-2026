#include <iostream>

using namespace std;

int main() {
    string s = "hello";
    char t;
    cin >> t;

    int found = s.find(t);
    if(found != -1){ // npos = no position => -1
        cout << "found at: " << found << endl;
    } else {
        cout << "not found" << endl;
    }

    return 0;
}