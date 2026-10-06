# Lecture 5: Two-Dimensional Arrays - Notes

## Topics

- [x] 1. 1D array sort, reverse
- [x] 2.1 Infinite loops
- [x] 2.2 Nested loops
- [x] 2.3 Multiplication table
- [x] 3. 2D array (matrix), declaration, MAXN
- [x] 4. Initializing 2D arrays
- [x] 5. Accessing elements
- [x] 6. Input, output
- [x] 7. freopen
- [x] 8. Table of multiplication in a matrix
- [x] 9. Max element in matrix
- [x] 10. Eye (1, 0)
- [x] 11. Eye (1, 2, 3)
- [x] 12. Opposite eye (1, 0)
- [ ] 13. Opposite eye (1, 2, 3)
- [x] 14.1 Symmetric with bool
- [ ] 14.2 Symmetric with return
- [ ] 14.3 Symmetric with counter
- [ ] 15. Max, min with location (n x m)
- [ ] 16. Max per row
- [ ] 17. Max per row sum
- [ ] 18. Snake

## Mistakes to show

- [ ] `i <= n` in the loop condition, out of bounds
- [ ] `a[j][i]` instead of `a[i][j]` on a non-square matrix
- [ ] `int a[n][m]` after `cin >> n >> m`
- [ ] `cout << endl` inside the inner loop of 2.3, table collapses
- [ ] `break` in the inner loop of 14.1, outer loop keeps going
- [ ] `mx = 0` in 9 with an all-negative matrix

## Questions to close with

- [ ] How many indices identify one element, and what is each?
- [ ] In `int a[5][7]`, how many rows, columns, elements?
- [ ] Which is valid for `int a[3][4]`: `a[2][3]` or `a[3][2]`?
- [ ] After `a[0][m-1]`, which element is visited next?
- [ ] Why may rows be omitted in an initializer list but never columns?
- [ ] Which cells satisfy `i + j == n - 1`, and why is that the anti-diagonal?
- [ ] In the symmetric check, why does the inner loop start at `i + 1`?
