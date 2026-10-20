#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello";
    char t;
    cin >> t;

    int found = s.find(t);
    if(found != -1){
        cout << "found at: " << found << endl;
    } else {
        cout << "not found" << endl;
    }


    return 0;
}