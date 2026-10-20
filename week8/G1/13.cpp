#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    string pattern;
    cin >> s >> pattern;

    int cnt = 0;
    int found = s.find(pattern, 0);

    while(found != string::npos){
        cnt++;
        found = s.find(pattern, found + pattern.size());
    }
    cout << cnt << endl;

    return 0;
}