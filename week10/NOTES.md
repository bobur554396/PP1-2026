# Lecture 8: STL (Part 1) - Notes

## Topics

- [ ] 1. What is STL: containers, algorithms, iterators, functions
- [ ] 2. Containers overview, which one to pick
- [ ] 3.1 Vector key functions
- [ ] 3.2 Creating a vector: `v`, `v(n)`, `v(n, x)`, `{list}`
- [ ] 3.3 Read n elements with push_back
- [ ] 3.4 `v[i]` versus `v.at(i)`
- [ ] 3.5 Three ways to iterate, and `for (int &x : v)`
- [ ] 3.6 Sort with a custom comparator
- [ ] 3.7 Erase and clear, iterators not indices
- [ ] 3.8 Insert
- [ ] 3.9 Read until 0
- [ ] 4.1 Set key functions
- [ ] 4.2 Set: unique and sorted, find, count
- [ ] 4.3 Distinct values from input
- [ ] 5.1 What is pair, first and second
- [ ] 5.2 Map insert and access, `[]` versus `insert`
- [ ] 5.3 Checking a key without creating it (count, find)
- [ ] 5.4 Student points, max over a map
- [ ] 5.5 Letter frequency with `freq[c]++`
- [ ] 5.6 Read a map from input, repeated key overwrites
- [ ] 6. Iterators: begin, end, rbegin, rend, `*it`, `it->first`
- [ ] 7. Algorithms: sort, reverse, find, count, max_element, accumulate
- [ ] 8. Summary table
- [ ] 9. Best practices
- [ ] Appendix A as lab and self-study material (pair comparator, vector of vectors)

## Mistakes to show

- [ ] `m["Carol"]` on a missing key, size grows from 1 to 2
- [ ] `i < v.size()` with `int i`, signed/unsigned warning
- [ ] Comparator with `>=` instead of `>`, sort can crash
- [ ] `v.erase(1)` instead of `v.erase(v.begin() + 1)`
- [ ] `*max_element(...)` without the `*`, prints nothing useful
- [ ] Using `find` result without comparing it to `end()`
- [ ] `for (int x : v) x *= 2;` and wondering why the vector is unchanged
- [ ] `vector<int> a(5)` versus `vector<int> a = {5}`
- [ ] `sort(s.begin(), s.end())` on a set, does not compile
- [ ] Erasing from a vector while looping over it
- [ ] Forgetting `-std=c++11`

## Questions to close with

- [ ] Which four things does the STL give you?
- [ ] What is the difference between `v[i]` and `v.at(i)`?
- [ ] After `vector<int> v = {4, 5, 6};` what are `front()`, `back()`, `size()`?
- [ ] What does `auto` do in `for (auto it = v.begin(); ...)`?
- [ ] What are the two members of a pair called?
- [ ] Why does inserting the same value into a set twice change nothing?
- [ ] How do you test for a key in a map without creating it?
- [ ] What does `freq[c]++` do the first time it sees `c`, and why does it work?
- [ ] Where does `end()` point, and why do we stop there?
- [ ] Why can `sort` not be used on a set or a map?
- [ ] What must a comparator return when the two values are equal?
- [ ] Name one case where a map beats a vector.
