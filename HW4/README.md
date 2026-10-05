# EECS 2510 – Non-Linear Data Structures
## Homework 4 – Big-O Analysis and Dynamic Bounded Arrays

This repository contains supporting material for **Homework 4**.

Homework 4 focuses on two important topics:

1. **Big-O analysis**
2. **Dynamic memory allocation in C++**

The main programming task is to modify the provided `BoundedArrayConst` implementation so that the capacity of the array is determined at runtime instead of being fixed at compile time.

---

# Homework Overview

## Problem 1 – Big-O Analysis

For Problem 1, analyze the provided mathematical functions and determine their **tightest Big-O upper bound**.

Focus on the term that grows the fastest as `N` becomes large.

Example:

```text
T(N) = 4N² + 3N + 7
```

The dominant term is `N²`, so:

```text
T(N) = O(N²)
```

Submit your solution to Problem 1 as:

```text
Problem1.pdf
```

---

# Problem 2 – BoundedArray

The starter code contains a class called:

```cpp
BoundedArrayConst
```

The maximum capacity is currently fixed:

```cpp
static const int MAX_NUM_ELEMENTS = 100;
```

and the data is stored using:

```cpp
double elements[MAX_NUM_ELEMENTS];
```

For Homework 4, create:

```cpp
BoundedArray
```

where the capacity is stored as a regular variable and the array is allocated dynamically.

---

# Capacity vs. Size

Example:

```text
Capacity = 8
Size     = 3
```

Conceptually:

```text
Index:    0    1    2    3    4    5    6    7
        +----+----+----+----+----+----+----+----+
Array:  | 4  | 7  | 2  |    |    |    |    |    |
        +----+----+----+----+----+----+----+----+
```

The **capacity** is the total amount of allocated storage.

The **size** is the number of elements currently stored.

Therefore:

```cpp
size() <= capacity()
```

must always be true.

---

# What Needs to Change?

The original class stores:

```cpp
static const int MAX_NUM_ELEMENTS = 100;
int numElements = 0;
double elements[MAX_NUM_ELEMENTS];
```

The new class should instead use:

- a variable for logical size,
- a variable for capacity,
- a pointer to dynamically allocated memory.

Conceptually:

```text
BoundedArray object

+----------------------+
| numElements          |
+----------------------+
| maxNumElements       |
+----------------------+
| elements ------------+------+
+----------------------+      |
                              |
                              v
                       Dynamic Memory
                       +--------+
                       | double |
                       +--------+
                       | double |
                       +--------+
                       |  ...   |
                       +--------+
```

---

# Constructors

The new class must support:

```cpp
BoundedArray(int numElements, int maxNumElements);
```

Example:

```cpp
BoundedArray arr(3, 10);
```

means:

```text
size     = 3
capacity = 10
```

The default capacity should be:

```text
100
```

---

# Dynamic Memory

Because capacity is determined at runtime, the underlying array must be allocated dynamically.

Example:

```cpp
new double[10]
```

Memory created with:

```cpp
new[]
```

must be released using:

```cpp
delete[]
```

---

# Destructor

If the object allocates memory dynamically, the destructor must release it.

Conceptually:

```text
Constructor
    |
    v
new double[capacity]
    |
    v
Object is used
    |
    v
Destructor
    |
    v
delete[] ...
```

Failing to release allocated memory causes a **memory leak**.

---

# Copying Objects

Consider:

```cpp
BoundedArray a(...);
BoundedArray b(a);
```

The two objects should be independent.

Changing:

```cpp
b[0]
```

should not change:

```cpp
a[0]
```

A shallow copy would look like:

```text
a.elements ----+
               |
               +----> [ 2 ][ 5 ][ 8 ]

b.elements ----+
```

A deep copy should look like:

```text
a.elements --------> [ 2 ][ 5 ][ 8 ]

b.elements --------> [ 2 ][ 5 ][ 8 ]
```

Pay particular attention to the copy constructor and assignment operator.

---

# Functions You Should Understand

| Function | Purpose |
|---|---|
| `BoundedArray()` | Create an empty bounded array |
| `BoundedArray(int numElements)` | Create an array with a specified logical size |
| `BoundedArray(int numElements, int maxNumElements)` | Create an array with a specified size and capacity |
| Copy constructor | Create an independent copy |
| Destructor | Release dynamically allocated memory |
| `size()` | Return logical size |
| `capacity()` | Return maximum capacity |
| `operator[]` | Access an element without bounds checking |
| `at()` | Access an element with bounds checking |
| `data()` | Return pointer to the underlying array |
| `operator=` | Copy one bounded array into another |
| `resize()` | Change logical size |
| `push_back()` | Add an element at the end |
| `pop_back()` | Remove the last element |
| `insert()` | Insert an element at an index |
| `erase()` | Remove an element at an index |
| `clear()` | Reset logical size to zero |

---

# Important Restrictions

Do **not** use STL container classes such as:

```cpp
vector<double>
```

or:

```cpp
array<double, 100>
```

The purpose of the assignment is to practice:

```text
Pointers
Dynamic Memory
new[]
delete[]
Deep Copy
Memory Management
```

---

# Recommended Implementation Order

```text
1. Private data members
2. Default constructor
3. Constructor with size
4. Constructor with size + capacity
5. size()
6. capacity()
7. operator[]
8. at()
9. data()
10. Destructor
11. Copy constructor
12. Assignment operator
13. resize()
14. push_back()
15. pop_back()
16. insert()
17. erase()
18. clear()
```

Compile and test frequently.

---

# Testing

Do not only test whether the program compiles.

Test:

- default construction,
- custom capacity,
- `push_back`,
- `insert`,
- `erase`,
- `resize`,
- copying,
- assignment,
- invalid indexes,
- full arrays,
- empty arrays.

Example:

```cpp
BoundedArray a(2, 5);

a[0] = 10;
a[1] = 20;

BoundedArray b(a);

b[0] = 99;
```

After this operation, `a` and `b` should remain independent.

---

# Compiling

If your files are:

```text
BoundedArray.h
BoundedArray.cpp
main.cpp
```

compile with:

```bash
g++ -std=c++17 main.cpp BoundedArray.cpp -o main
```

Run with:

```bash
./main
```

---

# Required Submission Files

Submit:

```text
BoundedArray.h
BoundedArray.cpp
main.cpp
```

Problem 1 should be submitted as:

```text
Problem1.pdf
```

Make sure your filenames match the assignment requirements exactly.

---

# Final Advice

Do not rewrite the entire class at once.

First understand how `BoundedArrayConst` works. Then identify each location that assumes a fixed `MAX_NUM_ELEMENTS` or a fixed-size array.

Compile frequently, test one function at a time, and pay particular attention to memory ownership and copying.
