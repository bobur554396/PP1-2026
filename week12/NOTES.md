# Lecture 9: STL (Part 2) - Notes

## Topics

- [ ] 1. Overview, why adapters exist, stack and queue have no index and no range-for
- [ ] 2.1 Stack key operations
- [ ] 2.2 Stack basic usage, `pop()` returns nothing
- [ ] 2.3 Reverse a sequence with a stack
- [ ] 2.4 Balanced brackets `()[]{}`
- [ ] 3.1 Queue key operations, push at back, pop at front
- [ ] 3.2 Queue basic usage, same loop gives the opposite order
- [ ] 3.3 Print queue simulation
- [ ] 4.1 Deque key operations
- [ ] 4.2 Deque as a flexible container, `push_front`, `dq[i]`
- [ ] 4.3 Deque as a sliding window
- [ ] 4.4 Palindrome from both ends
- [ ] 5. Comparison table
- [ ] 6. Real-world applications
- [ ] 7. Best practices
- [ ] Appendix A as lab and self-study material (copy to print, decimal to binary, queue of pairs)

## Mistakes to show

- [ ] `cout << st.pop();` does not compile, pop returns nothing
- [ ] `st.top()` on an empty stack, undefined behaviour not an error
- [ ] `for (int x : st)` on a stack, does not compile
- [ ] `st[0]`, a stack has no index
- [ ] Queue: `pop()` removes the front, not the back
- [ ] Brackets: forgetting the `st.empty()` check before `top()`, on input `)(`
- [ ] Brackets: forgetting the final `return st.empty()`, on input `([`
- [ ] `vector::push_front`, does not exist
- [ ] Printing a stack in a function taking it by reference, caller's stack is emptied
- [ ] Decimal to binary with no `n == 0` branch, prints nothing

## Questions to close with

- [ ] What do LIFO and FIFO mean, and which container is which?
- [ ] Why does `pop()` not return the removed value?
- [ ] What must you check before calling `top()` or `front()`?
- [ ] Which of the three allows access by index, and why not the others?
- [ ] Why is a stack the right tool for bracket matching?
- [ ] Name the three ways a bracket string can be invalid.
- [ ] Why does `vector` have no `push_front`, but `deque` does?
- [ ] The same print loop over a stack and a queue of 10, 20, 30: what does each print?
- [ ] How would you print a stack and still keep its contents?
- [ ] Why does `queue<pair<string, int> >` need a space before the last `>`?
