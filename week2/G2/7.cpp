#include <iostream>

using namespace std;

int main() {
    int age = 20;
    double balance = 300;
    string password = "kbtu123";

    // Check if a student is old enough to register
    cout << (age >= 18) << endl;   // true (1)

    // Check if user has enough money (tenge) for a bus ticket
    cout << (balance >= 150.0) << endl;   // true (1)

    // Check if entered password is correct
    cout << (password == "kbtu123") << endl;  // true (1)

    // Check if two exam scores are not equal
    int score1 = 85, score2 = 90;
    cout << (score1 != score2) << endl;  // true (1)

    return 0;
}