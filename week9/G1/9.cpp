#include <iostream>

using namespace std;

void greeting(string name){
    cout << "Hello, " + name + "!" << endl;
}

int main() {
    string name;
    cout << "Enter your name... \n";
    cin >> name;
    
    greeting(name);

    return 0;
}




