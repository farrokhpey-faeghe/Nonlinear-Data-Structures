# Homework 7: Balanced Trees

**EECS 2510 - Non-Linear Data Structures | Fall 2026 | Section 001**  
**Instructor:** Dr. Kishwar Ahmed  
**Assigned:** Friday, October 30, 2026  
**Due:** Friday, November 6, 2026, at 11:59 p.m.  
**Total:** 20 points

## About this guide

This guide explains the assignment requirements, the purpose of the starter files, and how to check your work. It does not provide completed implementations, experimental results, or a finished analysis. Use it alongside the official assignment PDF, which remains the authoritative source for requirements. Suggestions below are identified as guidance rather than additional grading requirements.

## 1. What you will do

| Part | Task | Points | Required submission |
| --- | --- | --- | --- |
| Problem 1 | Implement AVL insertion and insertion without rebalancing using the provided class. | 12 | `AVLTree.h`, `AVLTree.cpp`, and `main.cpp` |
| Problem 2 | Experimentally compare tree heights for random inputs and explain your observations. | 8 | `Homework7Solution.pdf` |

The assignment connects two ideas: preserving a binary search tree's ordering and controlling its height. First, build and validate the insertion operations. Then use them to conduct a fair comparison.

## 2. Understand the starter files

### `AVLTree.h`

The header defines two classes:

- `Node` stores a `double` key, a cached height, and pointers to its left child, right child, and parent.
- `AVLTree` declares the two insertion methods, stores a private `root`, and declares the destructor and its cleanup helper.

New nodes start with height `0` and null pointers. The required insertion interfaces are:

```cpp
void insert(Node* node);
void insertWithoutRebalance(Node* node);
```

Keep these interfaces usable by the assignment's test code. The handout allows you to add public or private members and helper functions as needed. For example, you will need some way to obtain the tree's height for Problem 2; the starter header does not provide one.

### `AVLTree.cpp`

The implementation already contains the destructor and recursive `deleteTree()` helper. These delete the nodes reachable from the tree's root. The insertion methods are declared in the header but are not yet defined in the supplied implementation.

You must write `main.cpp` for your tests and experimental driver. The starter files alone do not form a complete executable.

> **Ownership guidance:** Once a newly allocated node is inserted, treat that tree as its owner. Do not insert the same `Node*` into two trees or manually delete a node that a tree still owns. The supplied class also has raw owning pointers and no custom copy operations, so avoid copying tree objects by value.

## 3. Essential concepts and conventions

### BST ordering

Insertion first follows the binary search tree ordering rule. The supplied pseudocode goes left when the new key is smaller and right otherwise. Follow that comparison policy consistently, including when equal keys occur.

Rotations must preserve the in-order sequence of keys. With duplicates, do not assume equal keys must remain only on the right after rotations: rotations can change their structural placement while preserving a nondecreasing in-order sequence.

### Height

Use the convention in the handout:

| Structure | Height |
| --- | --- |
| Empty subtree | `-1` |
| Leaf node | `0` |
| Nonempty subtree | One plus the larger child-subtree height |

Height counts edges on the longest downward path to a leaf. It is different from node depth, which counts edges from the tree's root to that node.

Use this convention in both implementations and throughout the report. An off-by-one difference between conventions would make the comparison misleading.

### Balance factor

The handout defines a node's balance factor as:

**left-subtree height minus right-subtree height**

A positive value indicates a taller left subtree; a negative value indicates a taller right subtree. An AVL tree requires every node's balance factor to lie in `[-1, 1]` after insertion finishes. Checking only the root is insufficient.

### Rotations

A rotation changes a small group of links while preserving the in-order sequence. It does not create or remove keys.

Recognize all four imbalance patterns: left-left, right-right, left-right, and right-left. Some require one rotation; others require two. Use the handout's rebalancing pseudocode to determine the appropriate sequence, rather than deciding from a case name alone.

## 4. Problem 1: Implement the insertion operations

### A. Insertion with rebalancing

`insert(Node* node)` must place a node according to BST ordering and restore the AVL property along the affected ancestor path.

The handout supplies pseudocode for insertion, rebalancing, height updates, balance-factor calculation, right rotation, child replacement, and child assignment. Read these routines together: they depend on one another's pointer and height updates. A corresponding left rotation is also needed by the rebalancing routine.

Your implementation must handle an initially empty tree as well as insertion into an existing tree. After an insertion completes:

- Every inserted node must remain reachable from the actual root.
- The in-order traversal must remain nondecreasing.
- Parent and child links must agree.
- The root's parent must be null.
- Cached heights must agree with the current subtree structure.
- Every node must satisfy the AVL balance condition.

These properties are more useful for debugging than checking whether one printed key is correct.

### B. Insertion without rebalancing

`insertWithoutRebalance(Node* node)` is used to simulate an ordinary BST for Problem 2. It must insert according to the same key-comparison policy, but it must not perform rotations or otherwise rearrange the tree to restore balance.

**No rebalancing does not mean no height maintenance.** Problem 2 requires the actual height of this tree. If your height query reads cached heights, those heights must be maintained correctly after unbalanced insertion. Alternatively, a structural height traversal can compute the current height from child links. Either way, do not report the initial `height = 0` values as though they describe the completed tree.

Both insertion paths must maintain valid parent links.

### C. Pointer updates deserve special attention

For each rotation, account for:

- The parent above the rotated subtree, if there is one.
- The subtree's new root and the tree's stored root when appropriate.
- The subtree transferred between the two rotating nodes.
- Parent pointers for all affected non-null nodes.
- Height updates in an order that uses current child heights.

A transferred subtree can be empty or nonempty. A rotation can occur at the overall root or below it. Test both situations.

### D. Use the handout's sample tests carefully

The PDF includes two insertion sequences and their expected console output. Run both examples and compare your output with the handout. They exercise a single left rotation and a left-then-right rotation below the overall root.

The local pointers called `bRoot` and `cRoot` in those examples refer to particular allocated nodes. A local pointer does not automatically change when the tree's private `root` changes. Those examples retain the original overall root, but other insertion sequences may not.

For tests involving a rotation at the overall root, inspect the tree's actual current root through a suitable diagnostic interface. Do not mistake an old node pointer for the new root.

### E. Suggested test coverage

The following checks are recommended, not extra required deliverables:

| Test category | What to check |
| --- | --- |
| Empty tree and first insertion | Root initialization, leaf height, and null parent |
| All four imbalance patterns | Correct rebalancing and preserved key order |
| Rotation at the root | Correct replacement of the stored root |
| Rotation below the root | Correct reconnection to the ancestor |
| Nonempty transferred subtree | No lost nodes or inconsistent parent pointers |
| Increasing and decreasing keys | Behavior under strongly ordered insertion |
| Mixed keys and duplicate keys | Consistent comparisons and nondecreasing traversal |
| Small random inputs | Invariants after each insertion |
| Unbalanced insertion | BST ordering, accurate height, and no rotations |

A useful independent check computes subtree heights from the structure and compares them with cached values. For the unbalanced BST, check ordering and links without requiring AVL balance.

Validate small trees before running the larger experiment. Matching the supplied sample output alone does not establish correctness.

## 5. Problem 2: Compare BST and AVL heights

### A. Required experiment

Use each of the following sizes:

| `N` in the handout | Number of values per trial |
| --- | ---: |
| `10^2` | 100 |
| `10^3` | 1,000 |
| `10^4` | 10,000 |
| `10^5` | 100,000 |

These are powers of ten. In C++, `^` is bitwise XOR, not exponentiation; do not use expressions such as `10 ^ 3` to specify these sizes.

For **each** size, perform **10 trials**. In each trial:

1. Generate a fresh sequence of `N` random doubles in the interval `[0, 1]`.
2. Start with an empty ordinary BST and an empty AVL tree.
3. Insert the sequence into both trees, one value at a time, in the same order.
4. Use insertion without rebalancing for the BST and insertion with rebalancing for the AVL tree.
5. Record the final height of each tree after all `N` insertions.
6. Release the trees before starting the next trial.

This produces 40 paired trials and 80 final height measurements.

### B. Keep the comparison fair

**Use the same values in the same order for both trees within each trial.** Generating a different input for each tree would mix input differences with the effect of balancing.

Each tree needs its own node objects. The numeric key can be the same; the node pointer must be different. A node has only one set of child and parent links.

Do not reuse a populated tree across trials. Each trial measures a new tree built from exactly `N` inserted values, rather than adding another batch to a previous tree.

The PDF specifies random doubles in `[0, 1]` without prescribing a generator. As experimental guidance, use a documented, approximately uniform real-valued sampling method, initialize your generator once, and record the seed for reproducibility. Avoid resetting to the same seed before every trial, which would repeat the same sequence. Check your chosen generator's endpoint convention; a half-open range `[0, 1)` still produces values inside the requested interval.

### C. Summarize the measurements

For every `N`, calculate the minimum, arithmetic mean, and maximum of the 10 final heights for each tree type.

These statistics are taken **across trials**. They are not the minimum and maximum node depths within a single tree. Keep the average as a real-valued result rather than truncating it through integer division.

A suggested summary table is:

| N | BST min | BST mean | BST max | AVL min | AVL mean | AVL max |
| --- | --- | --- | --- | --- | --- | --- |
| 100 | | | | | | |
| 1,000 | | | | | | |
| 10,000 | | | | | | |
| 100,000 | | | | | | |

Retaining a separate table of all 10 trial pairs is recommended for checking your calculations, although the handout does not explicitly require a raw-data appendix.

### D. Explain the height reduction

The report must explain how much height reduction the AVL tree achieves. State how you quantify the reduction and use your measured data to support the discussion.

For example, you may compare the two mean heights using an absolute difference and, optionally, a percentage relative to the BST mean. If you instead average trial-by-trial percentage reductions, label that choice clearly: it is generally different from a percentage calculated from the two overall means.

Do not substitute a reduction in execution time for a reduction in height. The requested measurement is height; timing is not required by this assignment.

### E. Relate observations to theoretical growth

The handout asks you to compare the observed height growth with best-, average-, and worst-case Big-O expectations. Develop this analysis yourself using course material and your data.

Useful questions to guide your discussion:

- What tree shapes correspond to favorable and unfavorable heights?
- What assumptions underlie an average-case claim for an ordinary BST?
- What does AVL balancing guarantee about height?
- How do your measurements change as `N` increases by a factor of ten?
- Are the observed trends consistent with the theoretical expectations?
- Which cases are your random-input experiments likely to explore, and which cases do they not establish?

**The smallest and largest heights among 10 random trials are experimental extrema, not proofs of theoretical best- and worst-case behavior.** Likewise, a Big-O statement describes an asymptotic bound, not an exact predicted height for a particular trial.

Keep tree height, the cost of one insertion, and the total cost of building a tree distinct. If you discuss operation complexity, explain its connection to height rather than treating those quantities as interchangeable.

### F. Suggested report organization

Submit the Problem 2 report as **`Homework7Solution.pdf`**. A clear organization is:

1. **Method:** input sizes, 10 trials per size, random generation, shared insertion order, height convention, and how each tree's height was obtained.
2. **Results:** minimum, mean, and maximum heights for both tree types at every size.
3. **Height reduction:** a clearly defined comparison supported by the measurements.
4. **Growth analysis:** your comparison with the theoretical best-, average-, and worst-case expectations.
5. **Interpretation and limits:** explain what your random trials demonstrate and what they cannot establish.

A plot can support your discussion, but the handout does not explicitly require one. If included, label the axes and any logarithmic scale, and retain the numerical summary table.

## 6. Build and run

Once you have implemented the missing methods and written `main.cpp`, a typical GCC command is:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp AVLTree.cpp -o hw7
./hw7
```

On macOS, a typical Clang command is:

```bash
clang++ -std=c++11 -Wall -Wextra -pedantic main.cpp AVLTree.cpp -o hw7
./hw7
```

Run these commands from the directory containing the source files. The starter code uses C++11 features; these are example commands, not an additional course-specific compiler requirement. Follow any compiler or environment instructions provided by the instructor.

An optional debugging build with a compiler that supports these sanitizers is:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic -g -fsanitize=address,undefined main.cpp AVLTree.cpp -o hw7_debug
./hw7_debug
```

Compiler warnings and sanitizer reports can expose pointer errors, but they do not replace checks of ordering, height, and balance.

## 7. Common mistakes to avoid

- Implementing balanced insertion but leaving `insertWithoutRebalance()` undefined.
- Accidentally calling balanced insertion for both tree types.
- Reading stale cached heights from the unbalanced BST.
- Updating child links without updating the corresponding parent links.
- Losing a transferred subtree during a rotation.
- Failing to update the tree's root after a root rotation.
- Updating a node's height using stale child heights.
- Reusing one node object in both trees.
- Running only 10 trials total instead of 10 for each size.
- Using different sequences or insertion orders in a paired trial.
- Reporting traversal output or timing instead of final tree heights.
- Presenting the largest random-trial height as the theoretical worst case.

## 8. Submission checklist

### Problem 1

- [ ] Submit `AVLTree.h`, `AVLTree.cpp`, and `main.cpp`.
- [ ] Both insertion methods are implemented.
- [ ] Balanced insertion preserves BST ordering and restores AVL balance.
- [ ] Unbalanced insertion preserves BST ordering without rotations.
- [ ] Height measurements and parent pointers are correct for both paths.
- [ ] The supplied examples and additional structural checks pass.
- [ ] The program compiles with the intended compiler.

### Problem 2

- [ ] Use all four required values of `N`.
- [ ] Perform 10 fresh trials for each size.
- [ ] Use identical values and insertion order within each paired trial.
- [ ] Report minimum, mean, and maximum heights for both trees at each size.
- [ ] Explain the measured height reduction.
- [ ] Compare observed height growth with theoretical expectations.
- [ ] Submit the report as `Homework7Solution.pdf`.

**Scope reminder:** Search and node removal are not required. The provided destructor's cleanup is separate from implementing a tree deletion operation. Focus on correct insertion, a fair experiment, and an explanation supported by your own measurements.
