# Lecture 10: Struct and Pointers - Notes

## Topics

- [ ] 1. What is a pointer, address and dereference
- [ ] 1.1 Declaring pointers, `&x` versus `*p`
- [ ] 1.2 The array name is an address, `a[i]` is `*(a + i)`
- [ ] 1.3 Array as a function argument, why the size must be passed
- [ ] 1.4 Fill an array using a pointer
- [ ] 1.5 Looping with pointers, `arr + n` as the stop marker
- [ ] 2. What is a struct, members, the semicolon after `};`
- [ ] 2.1 Basic Student example, dot access
- [ ] 2.2 Read student data, why `cin >> s` does not work
- [ ] 2.3 freopen, remove before ejudge
- [ ] 2.4 Member functions, brace list in declaration order
- [ ] 2.5 Constructors, default and with arguments
- [ ] 2.6 Array of structs instead of parallel arrays
- [ ] 2.7 Sort by GPA with a comparator, `const Student &`
- [ ] 2.8 Find a student by name
- [ ] 2.9 All students above a threshold
- [ ] 2.10 Point example, free function versus member function
- [ ] 2.11 Pointer to struct, `p->name` versus `(*p).name`
- [ ] 2.12 Header and source separation, include guard, two files on the command line
- [ ] 3. Summary table
- [ ] 4. Best practices
- [ ] Appendix A as lab and self-study material (nullptr, vector of structs, by const reference)

## Mistakes to show

- [ ] Missing semicolon after `};` of the struct, error points at the next line
- [ ] `cin >> s;` for a whole struct
- [ ] `Student s = {"Bob", "25B001", 3.9};` with `int id;` in the struct
- [ ] Brace list in the wrong order after swapping two members
- [ ] Reusing a pointer after a loop moved it, without resetting it
- [ ] Dereferencing `arr + n`
- [ ] `*p.name` instead of `(*p).name` or `p->name`
- [ ] Reading `gpa` of a local `Student s;` with no constructor, garbage
- [ ] `g++ main.cpp` alone, undefined reference to `Student::print()`
- [ ] A header with no include guard, included twice
- [ ] `using namespace std;` inside a header

## Questions to close with

- [ ] What does a pointer store, and what does `*p` give you?
- [ ] What is the difference between `&x` in an expression and the `*` in `int* p`?
- [ ] What is `a[i]` really, written with a pointer?
- [ ] Why does an array parameter need a separate size parameter?
- [ ] What is `arr + n`, and what must you never do with it?
- [ ] What goes wrong without the semicolon after a struct definition?
- [ ] Why can a struct not be read with a single `cin >>`?
- [ ] What does a constructor do that a brace list does not?
- [ ] What is `p->gpa` shorthand for?
- [ ] Is a struct copied when passed by value? Is an array?
- [ ] What does an include guard prevent?
- [ ] Which command compiles a program split into main.cpp and student.cpp?
