#include <iostream>

using namespace std;

void hello(); // declare the function
int sum(int a, int b);

int main() {
    hello();

    cout << sum(2, 3) << endl;


    return 0;
}

// definition of the function
void hello(){
    cout << "Hello KBTU" << endl;
}

int sum(int a, int b){
    int res = a + b;
    return res;
}