#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "size: " << st.size() << endl;
    cout << "top: " << st.top() << endl;

    while (!st.empty()) {
        cout << st.top() << " ";   // read the top
        st.pop();                  // then remove it
    }
    cout << endl;
    return 0;
}