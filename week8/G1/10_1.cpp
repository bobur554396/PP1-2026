#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello";
    char t;
    cin >> t;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == t){
            cout << "found at: " << i << endl;
            return 0;
        }
    }
    cout << "not found" << endl;

    return 0;
}