#include <iostream>

using namespace std;

int main() {
    string line("KBTU"); 
    
    line = line + " is my university"; // concatination of the string

    cout << line << endl;

    cout << (line.size() == 0) << endl;
    cout << line.empty() << endl;    

    return 0;
}