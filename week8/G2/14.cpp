#include <iostream>

using namespace std;

int main() {
    // string s = "abababa";
    // string t = "aba";
    string s, t;
    cin >> s >> t;

    int found = s.find(t, 0);
    int cnt = 0;
    while(found != -1) { // string::npos
        cnt++;
        found = s.find(t, found + t.size());
    }

    cout << cnt << endl;


    return 0;
}