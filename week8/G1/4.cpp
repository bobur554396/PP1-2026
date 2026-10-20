#include <iostream>

using namespace std;

int main() {
    string line("KBTU"); 

    string line2 = line; // string line2(line); 
    

    cout << (line == line2) << endl;


    return 0;
}