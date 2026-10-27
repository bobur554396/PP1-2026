#include <iostream>

using namespace std;

// declaration of the function hello
void hello();
int sum(int a, int b);

int main() {
    
    hello();

    cout << sum(2, 3) << endl;

    return 0;
}

// Definition of the function hello
void hello() {
    cout << "Hello, World!" << endl;
}

int sum(int a, int b) {
    int res = a + b;
    return res;
}



