#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
    ()() - YES
    (()) - YES
    )() - NO
    (() - NO
    ))(( - NO
    ())(() - NO

    (}
*/

bool isValid(string s) {
    stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(') {
            st.push(c);
        } else {
            // a closer with nothing open
            if (st.empty()) 
                return false;  

            st.pop();
        }
    }

    // nothing may stay open
    return st.empty();                             
}

int main() {
    string s;
    cin >> s;
    // if(isValid(s))
    //     cout << "YES" << endl;
    // else
    //     cout << "NO" << endl;
    cout << (isValid(s) ? "YES" : "NO") << endl;
    return 0;
}