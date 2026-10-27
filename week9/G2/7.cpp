#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// declaration + definition
void hello(){
    cout << "Hello KBTU" << endl;
}

int sum(int a, int b){
    int res = a + b;
    return res;
}

int main() {
    hello(); // () - calling the function

    // int r = sum(2, 3);
    // cout << r << endl;
    cout << sum(2, 3) << endl;

    return 0;
}