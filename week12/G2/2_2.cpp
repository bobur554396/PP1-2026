#include <iostream>
#include <stack>

using namespace std;

int main() {
    /*
    3
    5 4 8

    8 4 5
    */
    int n, x;
    cin >> n;
    stack<int> st;
    for(int i = 0; i < n; i++){
        cin >> x;
        st.push(x);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    



    return 0;
}