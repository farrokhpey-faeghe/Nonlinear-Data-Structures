# Homework 3 – Indexed Binary Search Tree (Indexed BST)

## Overview

In this homework, you will work with an **Indexed Binary Search Tree (Indexed BST)**.

The provided implementation already includes:

- `search()` – searches for a node using its key
- `at()` – finds a node using its index

Your main task is to complete:

- `insert()` – insert a new node into the tree
- `remove()` – remove a node from the tree

Before implementing these functions, make sure you understand the concepts below.

---

# 1. Binary Search Tree (BST)

A Binary Search Tree follows this ordering rule:

- Keys smaller than the current node go to the **left subtree**.
- Keys greater than or equal to the current node go to the **right subtree**.

For example, inserting:

9, 4, 11, 2, 6

produces:

          9
         / \
        4   11
       / \
      2   6

To insert `6`:

1. Compare `6` with `9`
   - `6 < 9` → go left

2. Compare `6` with `4`
   - `6 > 4` → go right

3. The right child of `4` is empty, so `6` is inserted there.

---

# 2. Understanding the Node Class

Each node stores:

```cpp
double key;
int leftSize = 0;
Node* left = nullptr;
Node* right = nullptr;
Node* parent = nullptr;
