#include <iostream>
#include <string>

using namespace std;

int main() {
    int age = 20;
    double balance = 50.0;
    string password = "kbtu123";

    // Check if student is eligible to register (between 18 and 30)
    cout << (age >= 18 && age <= 30) << endl;   // true (1)

    // Check if user can travel (enough money OR has a student discount)
    bool hasStudentCard = true;
    cout << (balance >= 100.0 || hasStudentCard) << endl;   // true (1)

    // Check if entered password is NOT empty
    cout << (!(password == "")) << endl;   // true (1)

    return 0;
}