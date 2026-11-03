#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> freq;
    // for (char c : s) {
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        freq[c] = freq[c] + 1;
    }

    // for (auto &p : freq) {
    //     cout << p.first << ": " << p.second << endl;
    // }

    for (map<char, int>::iterator p = freq.begin(); p != freq.end(); ++p) {
        cout << p->first << ": " << p->second << endl;
    }
    return 0;
}