
# EECS 2510 — Homework 8: Red-Black Trees

**Course:** Non-Linear Data Structures  
**Semester:** Fall 2026  
**Instructor:** Dr. Kishwar Ahmed  
**Due Date:** Friday, November 13, 2026, at 11:59 PM  
**Total Points:** 20

---

## 1. Homework Overview

In Homework 8, you will work with **Red-Black Trees**, a type of self-balancing Binary Search Tree (BST).

This assignment focuses on two main objectives:

1. **Problem 1 (12 points):** Implement the insertion operation for a Red-Black Tree in C++.
2. **Problem 2 (8 points):** Compare the performance of Red-Black Trees and AVL Trees using different input sizes and insertion orders.

By completing this homework, you should gain a better understanding of:

- How Red-Black Trees maintain balance after insertion.
- How node colors and tree rotations are used to preserve tree properties.
- How Red-Black Trees differ from AVL Trees.
- How to measure insertion performance using wall-clock time.
- How input order affects tree height and insertion performance.
- How to analyze experimental results using Big-O complexity.

**Important:** This README provides explanations, guidance, and testing recommendations. It does not contain the homework solutions. You are responsible for implementing the required functionality and analyzing your experimental results.

---

## 2. Provided Files

You have been provided with the following starter files:

| File | Description |
|------|-------------|
| `RedBlackTree.h` | Contains the declarations of the Red-Black Tree classes and their members. |
| `RedBlackTree.cpp` | Contains the existing implementation of the destructor and recursive tree cleanup. |
| `EECS 2510 F2026 HW8.pdf` | Contains the official homework instructions and pseudocode. |

### Understanding RedBlackTree.h

The header file defines two classes.

**RBTNode**

Represents an individual node in the Red-Black Tree.

| Member | Description |
|--------|-------------|
| `key` | Stores the node's value as a double. |
| `red` | Represents the node's color. True means red; false means black. |
| `left` | Pointer to the left child. |
| `right` | Pointer to the right child. |
| `parent` | Pointer to the parent node. |

New nodes are initially red, and their child and parent pointers are initialized to `nullptr`.

**RedBlackTree**

Represents the Red-Black Tree itself.

The provided class includes:

- A constructor.
- A destructor.
- An `insert()` function declaration.
- A private `root` pointer.
- A private `deleteTree()` function.

The `insert()` function has not been implemented in the provided source file.

You may add additional member functions and data members as needed to complete your implementation.

### Understanding RedBlackTree.cpp

The provided implementation includes:

- `~RedBlackTree()` — Calls `deleteTree()` to release dynamically allocated nodes.
- `deleteTree()` — Recursively deletes the nodes in the tree.

The existing `deleteTree()` function is used for memory cleanup. It is not a Red-Black Tree node-removal operation.

You do not need to implement search or node removal for Problem 1.

---

# Problem 1 — Red-Black Tree Insertion (12 Points)

## 3. Understanding Red-Black Trees

A Red-Black Tree is a self-balancing Binary Search Tree.

Like a regular BST, it maintains the ordering of its keys. However, it also uses node colors and rotations to prevent the tree from becoming excessively unbalanced.

### 3.1 Red-Black Tree Properties

A valid Red-Black Tree must satisfy the following properties:

1. Every node is either red or black.
2. The root must always be black.
3. Every null leaf is considered black.
4. A red node cannot have a red child.
5. Every path from a node to its descendant null leaves must contain the same number of black nodes.

In addition, the normal Binary Search Tree ordering property must remain valid.

These properties help ensure that the height of the tree remains logarithmic relative to the number of nodes.

### 3.2 Why Is Balancing Necessary?

Consider inserting values into a regular Binary Search Tree.

If the values arrive in an unfavorable order, the tree can become highly unbalanced.

For example, inserting already sorted values into a basic BST may produce a chain-like structure.

This can increase the cost of operations that depend on tree height.

Red-Black Trees address this problem by using:

- **Recoloring:** Changing node colors when needed.
- **Rotations:** Rearranging local parent-child relationships without violating BST ordering.

These operations help preserve the Red-Black Tree properties.

---

## 4. Understanding the Insertion Process

Your primary task is to implement:

`RedBlackTree::insert(RBTNode* node)`

Insertion into a Red-Black Tree involves three general stages.

### Stage 1: Binary Search Tree Insertion

The new node must first be inserted according to the normal BST ordering rules.

Review how a BST determines whether a new node belongs in the left or right subtree.

Also consider how the parent pointer of the inserted node should be updated.

### Stage 2: Assign the Initial Color

A newly inserted Red-Black Tree node is initially red.

After insertion, the tree may violate one or more Red-Black Tree properties.

### Stage 3: Restore Red-Black Tree Properties

After inserting the node, the tree must be checked and rebalanced if necessary.

Depending on the relationships between the inserted node and its relatives, balancing may involve recoloring, rotations, or further checks higher in the tree.

Refer to the balancing algorithm on pages 2–3 of the homework PDF.

---

## 5. Understanding Parent, Grandparent, and Uncle

The balancing process frequently examines three relatives of the newly inserted node.

| Relationship | Meaning |
|-------------|---------|
| Parent | The node directly above the current node. |
| Grandparent | The parent of the current node's parent. |
| Uncle | The sibling of the current node's parent. |

Understanding these relationships is important because the balancing algorithm uses the colors and positions of these nodes to determine which operation is needed.

### Important Questions

Before implementing balancing, make sure you understand:

- How to determine whether a node has a parent.
- How to identify a node's grandparent.
- How to determine which child of the grandparent is the uncle.
- What happens when the uncle is `nullptr`.
- What happens when the current node is the root.

**Reminder:** A null uncle is treated as black when reasoning about Red-Black Tree properties.

---

## 6. Understanding Tree Rotations

Rotations are fundamental operations in self-balancing trees.

A rotation changes the local structure of the tree without changing the relative ordering of its keys.

### 6.1 Left Rotation

A left rotation rearranges the relationship between a node and its right child.

When studying a left rotation, pay attention to:

- Which node becomes the root of the rotated subtree.
- How the original node changes position.
- What happens to the transferred subtree.
- Which parent pointers must be updated.
- How the overall tree root may change.

### 6.2 Right Rotation

A right rotation is the corresponding operation involving a node and its left child.

The same pointer-management considerations apply.

### Important

After any rotation, verify that:

- BST ordering is preserved.
- Parent pointers are correct.
- Left and right child pointers are consistent.
- The rotated subtree remains connected to the rest of the tree.
- The tree's root pointer is updated when necessary.

Read the provided rotation pseudocode on pages 3–4 of the homework PDF before beginning your implementation.

---

## 7. Understanding the Balancing Cases

The homework provides the balancing procedure and explains the conditions that must be checked.

You should understand the following situations before writing your code.

| Situation | Concept to Review |
|-----------|------------------|
| Inserted node is the root | Root color requirement |
| Parent is black | Red-Black Tree properties after insertion |
| Parent and uncle are red | Recoloring and further balancing |
| Parent is red and uncle is black or null | Rotation and recoloring cases |
| Inside configuration | Relationship between the node, parent, and grandparent |
| Outside configuration | Rotation around the grandparent |

The inside configurations are often called zig-zag patterns.

The outside configurations are often called straight-line patterns.

Be sure to study how left-oriented and right-oriented configurations relate to each other.

**Do not assume that every insertion requires a rotation.**

The necessary operation depends on the current tree structure and node colors.

---

## 8. Functions to Understand

The assignment provides pseudocode for several useful operations.

You may use helper functions to organize your implementation.

| Function | Responsibility |
|----------|----------------|
| `RBTreeGetGrandparent` | Identifies a node's grandparent when one exists. |
| `RBTreeGetUncle` | Identifies a node's uncle when one exists. |
| `RBTreeRotateLeft` | Performs a left rotation while maintaining valid pointers. |
| `RBTreeRotateRight` | Performs a right rotation while maintaining valid pointers. |
| `RBTreeSetChild` | Updates a child pointer and its corresponding parent pointer. |
| `RBTreeReplaceChild` | Replaces an existing child connection. |
| `RBTreeBalance` | Restores Red-Black Tree properties after insertion. |

These functions are described in the assignment's pseudocode.

They are not already implemented in the supplied `RedBlackTree.cpp`.

You must determine how to incorporate the necessary functionality into your C++ implementation.

---

## 9. Recommended Development Approach

The following is a suggested workflow to help you organize your implementation.

### Step 1: Review the Starter Code

Read both provided C++ files carefully.

Make sure you understand the existing class structure and pointer relationships.

### Step 2: Review BST Insertion

Before implementing Red-Black Tree balancing, review how a regular BST inserts a node.

### Step 3: Study Rotations

Draw examples of left and right rotations.

Label the parent and child pointers before and after each operation.

### Step 4: Review the Balancing Algorithm

Read the pseudocode in the homework PDF.

Understand the conditions that determine when recoloring or rotations are necessary.

### Step 5: Organize Your Helper Functions

Determine which additional member functions are needed.

Keep the responsibilities of individual functions clear.

### Step 6: Test Incrementally

Test insertion with small sequences before using larger datasets.

Check the tree after each insertion rather than only checking the final structure.

---

## 10. Testing Problem 1

The homework includes an official test example on page 1.

The provided test inserts the following values in order:

`22, 11, 33, 55, 44`

The expected console output is:

```text
22
11 44
33 55
```

Use the complete test snippet from the homework PDF to verify your implementation.

The example uses a pointer named `aRoot` that references the first inserted node.

Remember that a pointer to an originally inserted node is not necessarily a pointer to the current tree root after arbitrary future rotations.

### Additional Testing Recommendations

You should also consider testing:

- Inserting into an empty tree.
- Inserting a second node.
- Insertion that does not require rotation.
- Insertion that requires recoloring.
- Insertion that requires a left rotation.
- Insertion that requires a right rotation.
- Insertion involving an inside configuration.
- Insertion that changes the root.
- Multiple consecutive insertions that require rebalancing.

These tests are intended to help you verify your implementation.

### Common Implementation Mistakes

Be careful about:

- Incorrect parent pointer updates.
- Forgetting to update the root pointer after a rotation.
- Accessing a null parent, grandparent, or uncle.
- Losing a subtree during rotation.
- Incorrectly handling recoloring.
- Failing to preserve BST ordering.
- Checking only the displayed keys without verifying the structure.

A tree may appear correct when printed but still contain incorrect pointers or colors.

---

# Problem 2 — Red-Black Tree vs. AVL Tree (8 Points)

## 11. Objective

In this problem, you will experimentally compare two self-balancing Binary Search Trees:

1. Red-Black Tree
2. AVL Tree

Your comparison must focus on:

- Total insertion wall-clock time.
- Final tree height.

You will examine how these measurements change with different input sizes and input orders.

The purpose of this experiment is to evaluate the behavior of both trees using your actual measurements.

---

## 12. Required Input Sizes

You must perform the experiments using the following input sizes:

| N | Number of Values |
|---|-----------------|
| 10² | 100 |
| 10³ | 1,000 |
| 10⁴ | 10,000 |
| 10⁵ | 100,000 |

For each input size, generate random double values in the interval:

`[0, 1]`

You must repeat each experiment **10 times**.

Each trial should use a newly generated vector.

---

## 13. Required Input Types

You must perform experiments using three different input orders.

### 13.1 Random Vectors

Generate a vector containing N random double values between 0 and 1.

Insert the elements into both trees in their original generated order.

### 13.2 Sorted Vectors

Generate N random double values and sort the entire vector using an efficient sorting algorithm.

Insert the sorted values into both trees.

**Important:** Do not include the time required to sort the vector in the insertion wall-clock measurement.

### 13.3 Partially Sorted Vectors

Generate a vector of N random double values.

Sort only the middle 50% of the vector.

The resulting vector must contain:

| Portion | Ordering |
|---------|----------|
| First 25% | Random |
| Middle 50% | Sorted |
| Last 25% | Random |

For example, when N = 100:

- The first 25 elements remain in random order.
- The middle 50 elements are sorted.
- The last 25 elements remain in random order.

This example explains how to construct the input, not the expected experimental result.

---

## 14. Experimental Procedure

For each input size and input type, perform the following steps.

### Step 1: Generate the Input

Create a vector containing N double values.

Prepare it according to the selected input type:

- Random
- Sorted
- Partially sorted

### Step 2: Test the Red-Black Tree

Create a new, empty Red-Black Tree.

Insert the values one at a time.

Record:

- Total wall-clock insertion time.
- Final tree height.

### Step 3: Test the AVL Tree

Create a new, empty AVL Tree.

Insert the same values in the same order.

Record:

- Total wall-clock insertion time.
- Final tree height.

### Step 4: Repeat the Experiment

Repeat the procedure 10 times for the same input size and input type.

Use a newly generated vector for each trial.

### Step 5: Calculate Averages

After completing the 10 trials, calculate:

- Average Red-Black Tree insertion time.
- Average AVL Tree insertion time.
- Average Red-Black Tree final height.
- Average AVL Tree final height.

Repeat the entire procedure for all required input sizes and input categories.

---

## 15. Understanding Wall-Clock Time

Wall-clock time is the actual elapsed time between the beginning and end of an operation.

In this homework, you need to measure the total elapsed time required to insert all N elements into a tree.

The C++ `<chrono>` library can be used to measure elapsed time.

### What Should Be Included?

Include the time required to perform the N insertions, including any balancing operations performed during insertion.

### What Should Be Excluded?

Do not include:

- Random vector generation.
- Sorting the input vector.
- Printing results.
- Calculating tree height.
- Calculating averages.

Start the timer immediately before the insertion operations and stop it immediately afterward.

### Important Measurement Recommendations

- Use the same input vector for both trees within each trial.
- Use a new tree for every trial.
- Use consistent compiler optimization settings.
- Report time using clearly identified units.
- Avoid unnecessary console output during timed operations.
- Apply the same measurement procedure to both trees.

These practices will help make the performance comparison more meaningful.

---

## 16. Understanding Tree Height

Tree height describes the maximum distance from the root to a leaf.

Tree height is important because the cost of many tree operations depends on the number of levels that must be traversed.

For this assignment, record the final height after all N values have been inserted.

### Important Considerations

Be consistent about whether your implementation defines height using:

- The number of edges on the longest root-to-leaf path.
- The number of nodes on the longest root-to-leaf path.

The assignment does not specify which convention to use.

Make sure both tree implementations use the same convention.

### Questions to Think About

- How does height change when N increases?
- How does input order affect the final height?
- How do the two self-balancing strategies differ?
- Are the measured heights consistent with the expected asymptotic behavior?

Do not determine which tree is faster based only on height.

Insertion time and final height are separate measurements.

---

## 17. Recording Experimental Results

You need to complete:

**4 input sizes × 3 input types × 10 trials = 120 paired comparisons.**

Each paired comparison includes one Red-Black Tree build and one AVL Tree build.

Therefore, the experiment includes 240 individual tree builds.

### Suggested Results Table

Use a table similar to the following to organize your average measurements.

| Input Type | N | RBT Avg. Time | AVL Avg. Time | RBT Avg. Height | AVL Avg. Height |
|------------|---|---------------|---------------|-----------------|-----------------|
| Random | 100 | — | — | — | — |
| Random | 1,000 | — | — | — | — |
| Random | 10,000 | — | — | — | — |
| Random | 100,000 | — | — | — | — |
| Sorted | 100 | — | — | — | — |
| Sorted | 1,000 | — | — | — | — |
| Sorted | 10,000 | — | — | — | — |
| Sorted | 100,000 | — | — | — | — |
| Partially Sorted | 100 | — | — | — | — |
| Partially Sorted | 1,000 | — | — | — | — |
| Partially Sorted | 10,000 | — | — | — | — |
| Partially Sorted | 100,000 | — | — | — | — |

Replace the dashes with your measured averages.

Remember to specify your time units.

You may also maintain a separate table containing the individual measurements for all 10 trials.

---

## 18. Analyzing Your Results

Problem 2 requires more than collecting timing measurements.

You must explain and interpret your results.

### 18.1 Comparing Insertion Times

Compare the average insertion times of Red-Black Trees and AVL Trees.

Consider the following questions:

- Which tree performs insertions faster for random input?
- Which tree performs insertions faster for sorted input?
- Which tree performs insertions faster for partially sorted input?
- Do the differences change as N increases?
- Are the observed performance differences consistent across input types?

Base your conclusions on your measurements.

### 18.2 Comparing Tree Heights

Compare the final heights of both trees.

Consider:

- Which tree has the smaller average height for each input category?
- How does height change when the input size increases?
- How does the insertion order influence the final tree structure?
- Are the measured heights consistent with the expected Big-O behavior?

Remember that Big-O notation describes how an algorithm or data structure scales as the input size increases.

It does not directly specify the exact measured tree height.

### 18.3 Understanding the Trade-Off

Both Red-Black Trees and AVL Trees are self-balancing Binary Search Trees.

However, they maintain balance using different rules.

Your experiment should help you investigate the relationship between:

- Balancing requirements.
- Work performed during insertion.
- Final tree height.
- Overall insertion performance.

Think about why a tree with a smaller final height is not necessarily the fastest tree to build.

### 18.4 Making Recommendations

The homework asks you to recommend a self-balancing tree for each of the three input types.

Your recommendations must be supported by the measured wall-clock times.

You should explain your reasoning separately for:

1. Random input.
2. Sorted input.
3. Partially sorted input.

Avoid making conclusions based on assumptions alone.

---

## 19. Recommended Project Organization

A possible organization of your project is:

```text
Homework8/
|
|-- RedBlackTree.h
|-- RedBlackTree.cpp
|-- avlRedBlackComparison.cpp
|-- README.md
```

If your AVL implementation is stored in separate files, include those files in your project as needed.

The provided homework explicitly identifies the following files for submission:

- `RedBlackTree.h`
- `RedBlackTree.cpp`
- `avlRedBlackComparison.cpp`

Follow the official submission instructions.

---

## 20. Compiling Your Program

When the required implementations are complete, you can compile the source files together.

For example:

```bash
g++ -std=c++17 -O2 RedBlackTree.cpp avlRedBlackComparison.cpp -o hw8
```

Run the compiled program using:

```bash
./hw8
```

If your AVL Tree implementation is located in another `.cpp` file, include that file in the compilation command.

On macOS, you may also use `clang++`.

**Note:** The example compilation command assumes that your comparison file includes a `main()` function and that all required member functions are implemented.

---

## 21. Common Mistakes to Avoid

### Problem 1

- Forgetting to update parent pointers during rotations.
- Forgetting to update the tree root.
- Dereferencing null pointers.
- Confusing BST insertion with Red-Black Tree balancing.
- Applying rotations without checking the relevant balancing conditions.
- Ignoring the root color property.
- Testing only one insertion sequence.

### Problem 2

- Including sorting time in insertion measurements.
- Using different input vectors for the two trees within a trial.
- Reusing trees instead of starting with empty trees.
- Running fewer than 10 trials.
- Forgetting one of the required input categories.
- Measuring only one input size.
- Using inconsistent height definitions.
- Comparing individual timing results instead of the required averages.
- Making recommendations without discussing the experimental evidence.

---

## 22. Submission Checklist

Before submitting, verify the following:

### Problem 1

- [ ] The insertion operation is implemented.
- [ ] The implementation follows the Red-Black Tree properties.
- [ ] Parent and child pointers are maintained correctly.
- [ ] Left and right rotations work correctly.
- [ ] The root remains black.
- [ ] The provided official test produces the expected output.
- [ ] Additional insertion cases have been tested.

### Problem 2

- [ ] Both Red-Black Tree and AVL Tree implementations are available.
- [ ] All four input sizes are tested.
- [ ] Random vectors are tested.
- [ ] Sorted vectors are tested.
- [ ] Partially sorted vectors are tested.
- [ ] Each experiment is repeated 10 times.
- [ ] The same values are used for both trees within each trial.
- [ ] Average insertion times are calculated.
- [ ] Average final heights are calculated.
- [ ] Tree heights are discussed using Big-O complexity.
- [ ] Recommendations are provided for all three input types.
- [ ] The experimental conclusions are supported by the collected measurements.

### Final Files

- [ ] `RedBlackTree.h`
- [ ] `RedBlackTree.cpp`
- [ ] `avlRedBlackComparison.cpp`

---

## 23. Important Notes

**Read the complete homework PDF before starting.**

The official assignment includes pseudocode and explanations for the insertion and balancing operations, including:

- Red-Black Tree insertion.
- Red-Black Tree balancing.
- Finding the grandparent and uncle.
- Left and right rotations.
- Updating and replacing child pointers.

These details are provided on pages 2–5.

For Problem 1, the assignment permits the use of pseudocode and code from the **Cormen textbook** and the **homework handout** only. No other external implementation sources are permitted.

Use this README to understand the requirements and organize your work, and use the official homework materials as the authoritative reference.

**The goal is to understand how the data structures work, implement the required operations independently, and support your performance conclusions with actual experimental results.**
