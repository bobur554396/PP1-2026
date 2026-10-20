# Lecture 6: Strings - Notes

## Topics

- [x] 1. What is a string
- [x] 2. String operations overview
- [x] 3.1 First string program
- [x] 3.2 Initialize string (with constructor)
- [x] 3.3 size, length, empty
- [x] 3.4 Copy a string from one to another
- [x] 3.5 Comparing for equality, lexicographical order
- [x] 3.6 Concatenation (+, +=)
- [x] 3.7 Accessing each element by loop
- [x] 3.8 Char to number (ASCII, `c - '0'`)
- [x] 3.9 front, back
- [x] 3.10 begin, end, iterators
- [x] 3.11 find, string::npos
- [x] 3.12 Is the second string inside the first
- [x] 3.13 Count substring occurrences (overlapping or not)
- [x] 3.14 getline, and cin.ignore after `cin >> n`
- [x] 3.15 substr
- [x] 3.16 erase
- [x] 3.17 append, insert
- [ ] 3.18 Doubled chars in sequence
- [ ] 3.19 Palindrome with iterators
- [x] 3.20 Palindrome with bool
- [ ] 3.21 Palindrome with return
- [ ] 3.22 Palindrome with left and right pointers
- [ ] 3.23 Palindrome by reversing
- [x] 3.24 stringstream: build mixed text
- [x] 3.25 stringstream: extract mixed types
- [x] 3.26 stringstream: count words
- [ ] 3.27 stringstream: parse int and double
- [ ] 3.28 stoi, stod, to_string
- [ ] 4. Summary table
- [ ] 5. Best practices
- [ ] Appendix A as lab and self-study material

## Mistakes to show

- [ ] `int pos = s.find(...)` then comparing with `string::npos`
- [ ] `i < s.size() - 1` on an empty string, unsigned wrap
- [ ] `cin >> s` and expecting the whole line
- [ ] `getline` straight after `cin >> n`, returns empty
- [ ] `"abc" + "def"`, does not compile
- [ ] `s[10]` past the end, silent, versus `s.at(10)`
- [ ] `stoi("abc")`, throws invalid_argument
- [ ] `s.back()` on an empty string
- [ ] A prompt printed in a judge solution

## Questions to close with

- [ ] What is the difference between `size()` and `length()`?
- [ ] What does `find` return when there is no match, and what type is it?
- [ ] Why does `cin >> s` not read a whole line, and what does?
- [ ] Why is `s.size() - 1` dangerous when the string may be empty?
- [ ] Which of `substr` and `erase` changes the original string?
- [ ] What does `c - '0'` compute, and why does it work?
- [ ] Where does `s.end()` point?
- [ ] What does `stoi` return for `"45.67"`, and what happens with `"abc"`?
- [ ] Why does comparing with `<` put `"Zoo"` before `"apple"`?
