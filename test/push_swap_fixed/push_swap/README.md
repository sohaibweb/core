*This activity has been created as part of the 42 curriculum by sabu-msa, <login2>.*

# push_swap

## Description

**push_swap** sorts a stack of integers using a second stack and a very small
set of operations (`sa sb ss pa pb ra rb rr rra rrb rrr`). The program reads
the integers as arguments (the first one is the top of stack `a`) and prints,
one per line on `stdout`, a list of operations that leaves `a` sorted in
ascending order with the smallest number on top.

The goal of the project is to experience algorithmic complexity concretely:
the cost of an algorithm is measured **in number of push_swap operations
generated**, not in CPU time.

The binary embeds four strategies and can select one at runtime:

| Flag | Strategy | Complexity (in operations) |
|---|---|---|
| `--simple` | Selection sort adaptation | O(n²) |
| `--medium` | Chunk-based sort (about 1.25·√n ranks per chunk) | O(n√n) |
| `--complex` | LSD radix sort on ranks (binary) | O(n log n) |
| `--adaptive` (default) | Chooses one of the above from the measured disorder | see below |

`--bench` (combinable with any selector, in any order) prints the metrics on
`stderr` after sorting; the operations stay on `stdout`.

## Instructions

### Compilation

```
make        # builds ./push_swap (flags: -Wall -Wextra -Werror, no relink)
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + all
```

### Execution

```
./push_swap 2 1 3 6 5 8
./push_swap "3 2 1"                    # one quoted argument also works
./push_swap --simple 5 4 3 2 1
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
./push_swap --bench --adaptive $ARG 2> bench.txt
```

Example of `--bench` output (on `stderr`):

```
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 9
[bench] sa: 0 sb: 0 ss: 0 pa: 2 pb: 2
[bench] ra: 4 rb: 0 rr: 0 rra: 1 rrb: 0 rrr: 0
```

Errors (non-integer argument, out of `int` range, duplicates, empty argument,
unknown option) print `Error` followed by a newline on `stderr`. With no
numbers the program prints nothing.

### Project layout

```
main.c                 entry point
parsing/               argument / flag parsing and validation
operations/            the 11 push_swap operations (they also count themselves)
sorting/               disorder metric, ranks, the 4 strategies, dispatcher
utils/                 ft_split, ft_atoi, printing helpers, bench output
include/ft_push_swap.h
```

No global variable is used: the two stacks, the selected mode and the
per-operation counters live in a single `t_ctx` structure passed by pointer.

## Algorithms and justification

### Disorder metric

Computed **before any move**, exactly as in the subject: over all pairs
`i < j`, a *mistake* is a pair with `a[i] > a[j]`; `disorder = mistakes /
total_pairs` (0 = sorted, 1 = reversed). It is kept as two integers
(`mistakes`, `pairs`) so thresholds are compared without floating point
(`disorder < 0.2` is `mistakes * 5 < pairs`) and printed with two decimals.
Computing it costs O(n²) CPU time but **zero** push_swap operations.

Before sorting, every value is replaced by its rank (0..n-1) in a copy of the
data (`index` field), which lets all algorithms work on a compact range.

### 1. Simple, O(n²): selection sort

Repeat n-2 times: bring the smallest remaining rank to the top of `a` using
`ra` or `rra` (whichever is shorter), then `pb`. Fix the last two with `sa` if
needed, then `pa` everything back (`b` is in descending order from top, so
`a` ends ascending).
Upper bound: each phase costs at most n/2 rotations + 1 push, so
≤ n²/2 + 2n operations = O(n²). Space: O(n) (stack `b` + the rank array).

### 2. Medium, O(n√n): chunks

*Phase 1 (`a → b`)*: choose a window width `c = ⌊1.25·√n⌋`. Walk through `a`;
if the top has rank `≤ end` it is pushed to `b` (and rotated to the bottom of
`b` with `rb` if it is in the lower half of the window, merged with the
following `ra` into one `rr` when possible), otherwise `ra`. After each push
the window slides by one.
Bound: the `c` smallest remaining ranks are always `≤ end`, so one full walk
over `a` (≤ n operations) pushes at least `c` elements; there are at most
`n/c = O(√n)` walks, so phase 1 costs O(n√n).

*Phase 2 (`b → a`)*: repeatedly bring the largest rank to the top of `b`
(`rb` or `rrb`, shortest way) and `pa`. If the second largest is closer, it
is pushed first and a `sa` fixes the order afterwards. Because phase 1 pushes
ranks in a window that slides upward, the largest remaining ranks stay within
O(√n) positions of one end of `b`, so each `pa` costs O(√n) rotations and
phase 2 is O(n√n) as well (informal argument; measured ratio ops / (n√n)
is 0.43–0.60 for n from 100 to 2000). Space: O(n).

The multiplier 1.25 was chosen by measurement (tested 0.5 to 3.0 times √n on
random inputs: 1.0 to 1.25 gave the fewest operations).

### 3. Complex, O(n log n): LSD radix sort

For each of the ⌈log₂ n⌉ bits of the rank, starting from the least
significant: for every element of `a`, `pb` if the bit is 0, else `ra`;
then `pa` everything back (stable). Each pass costs ≤ 2n operations, so the
total is ≤ 2n⌈log₂ n⌉ = O(n log n), independent of the input. Space: O(n).

### 4. Adaptive

| Regime | Disorder | Method | Class |
|---|---|---|---|
| Low | `< 0.2` | selection sort (1.) | O(n²) |
| Medium | `0.2 ≤ d < 0.5` | chunks (2.) | O(n√n) |
| High | `≥ 0.5` | radix (3.) | O(n log n) |

Rationale for the thresholds (they are the ones fixed by the subject): below
0.2 fewer than a fifth of the pairs are inverted, so the cheap, constant-light
selection strategy is enough; between 0.2 and 0.5 the input is clearly messy
but still has structure, and chunks have the best constants on this range
(about 600 operations for 100 random numbers, 5.3k for 500); from 0.5 up (a
uniformly random permutation has disorder ≈ 0.5), the data-independent
O(n log n) bound of radix is the safe choice, and it keeps the worst case
(reversed input) at ≤ 2n⌈log₂ n⌉.
Special cases: an already sorted stack prints nothing (0 operations) in every
mode, and with `--adaptive` a stack of at most 5 elements uses a dedicated
routine (constant size, so it does not change the asymptotic classes) that
sorts any 5 numbers in at most 10 operations.
Time and space bounds for each regime are those of the method used above:
O(n²), O(n√n), O(n log n) operations and O(n) extra space.

### Measured results (random inputs, checker `OK` in all runs)

| Input | `--simple` | `--medium` | `--complex` | default (adaptive) |
|---|---|---|---|---|
| 100 numbers (avg) | ~1460 | ~600 | 1084 | ~740 |
| 500 numbers (avg) | ~31900 | ~5360 | 6784 | ~5870 |

A random permutation has disorder very close to 0.5, so the default mode
picks medium or complex depending on the input; both are below the "good"
thresholds of the subject, and medium is below the "excellent" ones.

## Contributions

- **sabu-msa**: TODO (describe exactly what you did)
- **<login2>**: TODO (describe exactly what your partner did)

## Resources

- Donald Knuth, *The Art of Computer Programming, Vol. 3: Sorting and Searching*
- Big-O / algorithmic complexity: https://en.wikipedia.org/wiki/Big_O_notation
- Radix sort: https://en.wikipedia.org/wiki/Radix_sort
- Selection sort: https://en.wikipedia.org/wiki/Selection_sort
- Bucket / chunk partitioning: https://en.wikipedia.org/wiki/Bucket_sort

### Use of AI

AI (Claude) was used to: review the project against the subject and list what
was missing; wire the four strategies together; implement the `--simple`,
`--medium`, `--complex`, `--adaptive` and `--bench` options and the operation
counters; tune the chunk size and the `b → a` phase; and draft this README.
Test scripts (exhaustive permutations for n ≤ 7, random inputs up to 2000
numbers, AddressSanitizer runs, `norminette`) were also produced with its help.
All generated code was reviewed, tested with the provided checker and is
understood and defended by both authors.
