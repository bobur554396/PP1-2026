#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // aaabbccc
    /*
    a: 3
    b: 2
    c: 3
    */
    string s;
    cin >> s;

    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    for (map<char, int>::iterator p = freq.begin(); p != freq.end(); ++p) {
        cout << p->first << ": " << p->second << endl;
    }
    return 0;
}