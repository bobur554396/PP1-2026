#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s = "KBAaTU";

    sort(s.begin(), s.end()); // sort([start_add, end_add))

    cout << s << endl;


    return 0;
}