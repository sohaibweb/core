*This activity has been created as part of the 42 curriculum by sabu-msa, yal-lata.*

# push_swap

## Description

**push_swap** sorts a stack of integers using two stacks (`a` and `b`) and a limited set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). The program reads a list of integers and prints, one per line, a sequence of operations that sorts stack `a` in ascending order. The cost of an algorithm is measured in the **number of operations generated**.

The program embeds four strategies, selectable at runtimee:

| Flag | Strategy | Complexity |
|------|----------|------------|
| `--simple` | Selection sort | O(n²) |
| `--medium` | Chunk-based sort | O(n√n) |
| `--complex` | LSD radix sort | O(n log n) |
| `--adaptive` *(default)* | Chosen from the measured disorder | O(n²) / O(n√n) / O(n log n) |

The optional `--bench` flag prints on `stderr` the disorder, the strategy used with its complexity class, the total number of operations and the count of each operation.

## Instructions

Compilation:

```bash
make        # builds ./push_swap
make clean
make fclean
make re
```

Execution:

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <list of integers>
```

Example:

```bash
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
```

## Algorithms: explanation and justification

Before sorting, every value is replaced by its rank (0 … n-1) stored in each node's `index` field, so all algorithms work independently of the actual values.

**Disorder** is the number of pairs `(i, j)`, `i < j`, with `a[i] > a[j]`, divided by the total number of pairs `n(n-1)/2`. It is `0` for a sorted stack and `1` for a reversed one, and it is computed before any move.

### 1. Simple: selection sort, O(n²)

Repeatedly find the smallest remaining rank in `a`, bring it to the top with `ra` or `rra` (the shorter direction) and `pb` it. When two elements remain, fix them with at most one `sa`, then `pa` everything back.

*Why:* it is the natural baseline and is very cheap when the input is nearly sorted, since the next minimum is usually already near the top.
*Complexity:* n pushes, each preceded by at most n/2 rotations, giving O(n²) operations and O(n) memory.

### 2. Medium: chunk (sliding-window) sort, O(n√n)

Ranks are processed in a window of size `⌊√n⌋`. Phase 1 scans `a`: if the top rank is inside the window it is pushed to `b` (and rotated with `rb` if it is in the lower half of the window), and the window slides by one; otherwise `ra`. Phase 2 repeatedly brings the largest rank of `b` to the top (`rb`/`rrb`) and `pa`s it.

*Why:* the window keeps `b` roughly ordered, so the maximum is always close to the top.
*Complexity:* the window holds Θ(√n) of the n elements, so reaching one in phase 1 takes Θ(√n) rotations on average; in phase 2 each maximum is O(√n) from the top of `b`. Total O(n√n) operations, O(n) memory.

### 3. Complex: LSD radix sort, O(n log n)

For each bit of the rank, from the lowest to the highest: `ra` if the bit is 1, `pb` otherwise, then `pa` everything back. Each pass is a stable partition, so `a` is sorted after the last bit.

*Why:* its cost is regular and independent of the input structure, and it only needs push and rotate operations.
*Complexity:* ⌈log₂ n⌉ passes of at most 2n operations each, giving O(n log n) operations and O(n) memory.

### 4. Adaptive: disorder-driven strategy

| Disorder | Method | Complexity |
|----------|--------|------------|
| `< 0.2` | Selection sort | O(n²) |
| `0.2 ≤ d < 0.5` | Chunk sort | O(n√n) |
| `≥ 0.5` | Radix sort | O(n log n) |

Stacks of 5 elements or fewer are sorted with dedicated routines.

*Rationale for the thresholds:*
- **Low disorder:** few inversions mean elements are already near their place, so selection sort needs few rotations and has no fixed overhead.
- **Medium disorder:** too messy for selection sort, but the sliding window still exploits the partial order and is the cheapest option.
- **High disorder:** the input structure can no longer be exploited, so the predictable O(n log n) radix sort is the safe choice and avoids the quadratic regime.

*Complexity argument:* the adaptive strategy runs exactly one of the algorithms above, so its operation count is that of the selected algorithm: O(n²) for disorder < 0.2, O(n√n) for 0.2 ≤ disorder < 0.5 and O(n log n) for disorder ≥ 0.5. Space is O(n) in every regime.

## Contributions

- **sabu-msa:** `main.c`, the Makefile, the header and all utility functions, argument parsing and error handling, the swap, push and reverse-rotate operations, the disorder metric, `push_swap.c` (selection of the sorting strategy), `sort_small`, as well as fixing side issues and improving the stability of the project.
- **yal-lata:** the chunk sort, radix sort and selection sort algorithms, the benchmark mode (`--bench`) and the rotate operations.
- **Together:** testing the project.

Both learners reviewed the whole code base and can explain every part of it.

## Resources

- Donald Knuth, *The Art of Computer Programming, Vol. 3: Sorting and Searching*.
- [Big-O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)

### Use of AI

AI was used as a learning and review aid, not as a code generator: to explain complexity notation and how radix and chunk sorting map onto the Push_swap operations, to suggest test ideas, and to help draft and proofread this README. All code was written, reviewed and tested by the two learners, who can explain and defend every part of it.
