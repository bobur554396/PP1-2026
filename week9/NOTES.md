# Lecture 7: Functions - Notes

## Topics

- [ ] 1. What is a function, why we need them
- [ ] 2.1 sort, reverse (`<algorithm>`)
- [ ] 2.2 tolower, toupper (`<cctype>`), they return int
- [ ] 2.3 isalpha, isdigit, isalnum, ispunct
- [ ] 2.4 sqrt, pow (`<cmath>`), max, min (`<algorithm>`)
- [ ] 3.1 Declaration and definition, prototype before main
- [ ] 3.2 Function parameters, parameter vs argument
- [ ] 3.3 Types of functions: returning a value, void
- [ ] 3.4 Local vs global variables, scope
- [ ] 4.1 hello
- [ ] 4.2 hello with a parameter
- [ ] 4.3 sum of two
- [ ] 4.4 max of two
- [ ] 4.5 my power, negative exponent
- [ ] 4.6 factorial
- [ ] 4.7 isPrime
- [ ] 4.8 toUpper, toLower, isDigit written by hand
- [ ] 5. Summary table
- [ ] 6. Best practices
- [ ] Appendix A as lab and self-study material (by value, by reference, arrays, overloading)

## Mistakes to show

- [ ] Calling a function defined below main with no prototype
- [ ] `cout << tolower('A')` prints 97, not `a`
- [ ] `if (isalnum(c) == 1)`, the value is 8 on g++
- [ ] A value-returning function with a missing `return`
- [ ] `int x = sayHi();` where sayHi is void
- [ ] `max(3, 4.5)`, does not compile
- [ ] Naming your own function `max` with `using namespace std;`
- [ ] `void increment(int x)` and expecting the caller's variable to change
- [ ] Passing an array and trying to find its size inside the function
- [ ] `factorial(21)`, silent overflow

## Questions to close with

- [ ] What is the difference between a declaration and a definition?
- [ ] Why must the prototype come before the call?
- [ ] What is the difference between a parameter and an argument?
- [ ] What can you not do with the result of a void function?
- [ ] Why does `tolower` need a `(char)` cast when you print it?
- [ ] When does a parameter need `&`, and when is it pointless?
- [ ] Why must an array parameter be accompanied by a size parameter?
- [ ] Which part of a 2D array parameter may be omitted, and which may not?
- [ ] Why does `isPrime` loop only while `i * i <= n`?
- [ ] Where does a local variable live, and why avoid globals?
