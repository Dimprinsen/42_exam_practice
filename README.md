# 42 Exam Practice

Practice repository for 42 school exam questions across multiple ranks.

## Included

- Rank 03: [exam03](exam03)
- Rank 04: [exam04/vbc](exam04/vbc)

Each folder contains standalone exam-style C exercises.

## Exercises

### Rank 03

- [filter](exam03/filter)
	Replace all occurrences of a target substring from stdin with `*` characters of the same length.
- [gnl](exam03/gnl)
	Minimal `get_next_line` implementation reading one line at a time from a file descriptor.
- [n_queens](exam03/n_queens)
	Backtracking solver that prints all valid queen placements for an `n x n` chessboard.
- [permutations](exam03/permutations)
	Generate and print all permutations of the provided input string.
- [powerset](exam03/powerset)
	Recursive subset-sum style search that prints subsets whose sum matches a target value.

### Rank 04

- [vbc](exam04/vbc)
	Small arithmetic expression parser/evaluator supporting digits, `+`, `*`, and parentheses.
	Includes [run_tests.sh](exam04/vbc/run_tests.sh) for quick validation against sample cases.