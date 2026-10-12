# EECS 2510 – Homework Assignment 5
## O(n²) and O(n log n) Sorting Algorithms

**Course:** EECS 2510 – Non-Linear Data Structures  
**Semester:** Fall 2026  
**Instructor:** Dr. Kishwar Ahmed  
**Assigned:** Friday, October 9, 2026  
**Due Date:** Friday, October 16, 2026, at 11:59 PM  
**Total Points:** 10

---

## 1. Homework Overview

In this homework, you will implement and compare two sorting algorithms in C++:

1. **Insertion Sort**
2. **Merge Sort**

The main goal is to understand how these sorting algorithms work, analyze their time complexities, and compare their actual execution times using randomly generated datasets.

You will also learn how the running time of an algorithm changes as the input size increases.

### Learning Objectives

By completing this assignment, you should be able to:

- Implement sorting algorithms in C++.
- Understand the difference between O(n²) and O(n log n) time complexities.
- Work with `std::vector<int>`.
- Understand pass-by-reference parameters.
- Implement a recursive sorting algorithm.
- Measure wall-clock execution time.
- Calculate average execution times across multiple trials.
- Compare theoretical time complexity with experimental results.

---

## 2. Assignment Requirements

This homework consists of three parts.

| Part | Task | Points |
|---|---|---|
| A | Implement Insertion Sort | 3 |
| B | Implement Merge Sort | 3 |
| C | Measure and compare execution times | 4 |
| **Total** | | **10** |

**Important:** Although the assignment introduction mentions three sorting algorithms, Parts A and B specify only Insertion Sort and Merge Sort. Follow the explicitly defined requirements unless the instructor provides further clarification.

---

# Part A – Insertion Sort (3 Points)

## 3. Problem Description

Implement an Insertion Sort function using the following function header:

```cpp
void insertionSort(std::vector<int>& numbers);
```

Your function must sort the given vector in ascending order.

### What Is Insertion Sort?

Insertion Sort is a sorting algorithm that builds a sorted portion of an array or vector one element at a time.

It works similarly to arranging playing cards in your hand.

At each step, the algorithm takes the next element and inserts it into its correct position among the previously sorted elements.

### Example

Consider the following vector:

```text
[8, 3, 5, 1, 4]
```

The algorithm gradually builds the sorted portion.

| Step | Vector |
|---|---|
| Initial | [8, 3, 5, 1, 4] |
| 1 | [3, 8, 5, 1, 4] |
| 2 | [3, 5, 8, 1, 4] |
| 3 | [1, 3, 5, 8, 4] |
| 4 | [1, 3, 4, 5, 8] |

Final result:

```text
[1, 3, 4, 5, 8]
```

### Understanding the Function Header

```cpp
void insertionSort(std::vector<int>& numbers);
```

- `void`: The function does not return a value.
- `insertionSort`: The function name.
- `std::vector<int>`: A vector containing integers.
- `&`: Passes the vector by reference.
- `numbers`: The vector that will be sorted.

### What Does Pass by Reference Mean?

The `&` symbol is important.

When a vector is passed by reference, the function works directly with the original vector instead of creating a copy.

For example:

```cpp
std::vector<int> values = {8, 3, 5, 1, 4};

insertionSort(values);
```

After the function finishes, `values` should contain:

```text
[1, 3, 4, 5, 8]
```

You do not need to return the sorted vector because the original vector is modified.

### Expected Behavior

Your function should:

- Accept a vector of integers.
- Sort the vector in ascending order.
- Modify the original vector.
- Work correctly for vectors of different sizes.

### Time Complexity

Insertion Sort has the following time complexities:

| Case | Time Complexity |
|---|---|
| Best case | O(n) |
| Average case | O(n²) |
| Worst case | O(n²) |

For large datasets, the quadratic growth rate can make Insertion Sort significantly slower.

---

# Part B – Merge Sort (3 Points)

## 4. Problem Description

Implement Merge Sort using the following function header:

```cpp
void mergeSort(std::vector<int>& numbers, int p, int r);
```

The function must sort the specified portion of the vector in ascending order.

### What Is Merge Sort?

Merge Sort is a sorting algorithm based on the **Divide and Conquer** technique.

The main idea is to:

1. Divide the input into smaller parts.
2. Recursively sort each part.
3. Merge the sorted parts into a sorted result.

### Example

Consider:

```text
[8, 3, 5, 1, 4]
```

The vector is divided into smaller parts.

```text
           [8, 3, 5, 1, 4]
                /    \
          [8, 3, 5]  [1, 4]
           /    \      / \
        [8, 3]  [5]  [1] [4]
         /  \
       [8]  [3]
```

After dividing, the smaller portions are sorted and merged.

```text
[8] + [3]       -> [3, 8]

[3, 8] + [5]    -> [3, 5, 8]

[1] + [4]       -> [1, 4]

[3, 5, 8] + [1, 4]
                 -> [1, 3, 4, 5, 8]
```

Final result:

```text
[1, 3, 4, 5, 8]
```

### Understanding the Function Header

```cpp
void mergeSort(std::vector<int>& numbers, int p, int r);
```

| Parameter | Description |
|---|---|
| `numbers` | The vector containing the data |
| `p` | Starting index of the portion to sort |
| `r` | Ending index of the portion to sort |

The assignment defines `p` and `r` as the start and end indices.

For example:

```cpp
std::vector<int> values = {8, 3, 5, 1, 4};

mergeSort(values, 0, 4);
```

Here:

```text
p = 0
r = 4
```

The function sorts the entire vector because the indices range from 0 to 4.

For a vector containing N elements, the initial function call for sorting the full vector will be:

```cpp
mergeSort(numbers, 0, N - 1);
```

### Important Concepts

**Recursion**

Merge Sort uses recursive function calls to process smaller portions of the input.

**Base Case**

Every recursive algorithm must have a stopping condition.

For Merge Sort, recursion stops when the current portion contains at most one element.

**Merging**

After the smaller portions have been sorted, they must be combined while maintaining ascending order.

### Time Complexity

| Case | Time Complexity |
|---|---|
| Best case | O(n log n) |
| Average case | O(n log n) |
| Worst case | O(n log n) |

Merge Sort generally scales better than Insertion Sort as the input size becomes large.

A typical array-based Merge Sort implementation uses O(n) additional space for merging.

---

# Part C – Experimental Performance Comparison (4 Points)

## 5. Problem Description

After implementing both sorting algorithms, you must compare their actual execution times.

The purpose of this part is to investigate how the algorithms behave as the input size increases.

You will generate random vectors, sort them using both algorithms, and measure their wall-clock execution times.

---

## 6. Required Input Sizes

Your experiments must use the following vector sizes:

```text
N = 10
N = 100
N = 1000
N = 10000
```

Each vector must contain N randomly generated integers.

Every integer must be between:

```text
0 and 999
```

inclusive.

### Example

For N = 10, a random vector might look like:

```text
[428, 12, 875, 63, 201, 990, 7, 451, 88, 326]
```

This is only an example.

The actual values should be generated randomly during your experiment.

---

## 7. Number of Trials

For each input size, repeat the experiment **10 times**.

For example, when:

```text
N = 100
```

You must:

1. Generate a random vector containing 100 integers.
2. Sort the vector using Insertion Sort.
3. Record its execution time.
4. Sort the same input values using Merge Sort.
5. Record its execution time.
6. Repeat the experiment using newly generated random inputs until you have completed 10 trials.

Then calculate the average execution time for each algorithm.

Repeat the same procedure for all four input sizes.

### Important: Use the Same Input for Both Algorithms

To make the comparison fair, both sorting algorithms should receive identical input values during each trial.

For example:

```cpp
std::vector<int> original = /* randomly generated values */;

std::vector<int> insertionInput = original;
std::vector<int> mergeInput = original;
```

You can then sort each copy independently.

This is important because both algorithms modify the vectors they receive.

Do not run Merge Sort on a vector that has already been sorted by Insertion Sort unless that is the experiment you specifically intend to perform.

---

## 8. Measuring Wall-Clock Time

Wall-clock time is the actual elapsed time between the beginning and end of an operation.

In C++, you can use the `<chrono>` library to measure elapsed time.

For example:

```cpp
#include <chrono>
```

A useful clock is:

```cpp
std::chrono::steady_clock
```

### General Measurement Procedure

1. Record the starting time.
2. Execute the sorting algorithm.
3. Record the ending time.
4. Calculate the elapsed time.
5. Convert the result to milliseconds.

### Important Notes

- Measure the sorting operation itself.
- Do not include random vector generation in the sorting time.
- Do not include printing the vector in the sorting time.
- Use the same timing method for both algorithms.
- Store the timing results so you can calculate their averages.

For very small inputs, execution times may be extremely short. A high-resolution measurement in milliseconds may produce fractional values.

---

## 9. Calculating Average Execution Time

For each input size, you must run each algorithm 10 times.

After recording the execution times, calculate the average.

### Formula

**Average Time = (Sum of 10 Execution Times) / 10**

For example, suppose the measured execution times for one algorithm are:

```text
Trial 1:  0.10 ms
Trial 2:  0.12 ms
Trial 3:  0.11 ms
Trial 4:  0.13 ms
Trial 5:  0.10 ms
Trial 6:  0.12 ms
Trial 7:  0.11 ms
Trial 8:  0.14 ms
Trial 9:  0.10 ms
Trial 10: 0.12 ms
```

The average is:

```text
Average = 1.15 / 10

Average = 0.115 ms
```

These numbers are illustrative only and are not actual experimental results.

You must use the execution times measured by your own program.

---

## 10. Recording Your Results

You can organize your measurements using a table like the following.

### Individual Trial Results

| Trial | Insertion Sort (ms) | Merge Sort (ms) |
|---|---|---|
| 1 | | |
| 2 | | |
| 3 | | |
| 4 | | |
| 5 | | |
| 6 | | |
| 7 | | |
| 8 | | |
| 9 | | |
| 10 | | |
| **Average** | | |

Create or maintain these measurements for each input size.

### Final Comparison Table

After calculating the averages, prepare a summary table:

| Input Size (N) | Insertion Sort Average (ms) | Merge Sort Average (ms) |
|---|---|---|
| 10 | | |
| 100 | | |
| 1000 | | |
| 10000 | | |

Use your actual experimental results to complete this table.

---

# 11. Analyze Your Results

In addition to reporting average execution times, you must answer the questions from the homework assignment.

### Question 1: Which Algorithm Is Faster for Small N?

Compare the execution times for:

```text
N = 10
N = 100
```

Identify which algorithm performs better based on your measurements.

Consider how the simplicity and overhead of each algorithm may affect performance for small inputs.

### Question 2: Which Algorithm Is Faster for Large N?

Compare the execution times for:

```text
N = 1000
N = 10000
```

Explain which algorithm performs better and how the difference changes as the input size increases.

### Question 3: How Do the Execution Times Compare with Big O Complexity?

Compare your experimental measurements with the theoretical average-case time complexities.

| Algorithm | Average Time Complexity |
|---|---|
| Insertion Sort | O(n²) |
| Merge Sort | O(n log n) |

In your explanation, consider:

- How execution time changes as N increases.
- Whether the measured growth is consistent with the theoretical complexity.
- Why algorithms with different time complexities may behave similarly for small inputs.
- Why constant factors and implementation overhead can influence actual running times.

Remember that Big O notation describes asymptotic growth, not exact execution time in milliseconds.

Your conclusions should be supported by your own experimental data.

---

# 12. Suggested Program Organization

Your source file should contain the two required sorting functions:

```cpp
void insertionSort(std::vector<int>& numbers);
```

```cpp
void mergeSort(std::vector<int>& numbers, int p, int r);
```

You may also use helper functions to organize your implementation.

For example, helper functions may be useful for:

- Generating random vectors.
- Merging sorted portions.
- Measuring execution time.
- Calculating averages.
- Displaying experimental results.

Use `main()` to coordinate the required experiments.

Make sure both sorting algorithms are tested with the appropriate input sizes.

---

# 13. Submission Requirements

You must submit the following files.

### File 1: C++ Source Code

**Required filename:**

```text
sortComparison.cpp
```

This file should contain your implementations and experimental comparison code.

### File 2: Performance Report

**Example filename:**

```text
Homework5Solution.pdf
```

Your report must contain:

- Average wall-clock execution times in milliseconds.
- Results for all four input sizes.
- A comparison of the algorithms for small N.
- A comparison of the algorithms for large N.
- An explanation of how your measurements relate to the theoretical average-case Big O complexities.

**Important:** Your measured results and written answers must be submitted in a separate file from your C++ source code.

---

# 14. Compile and Run Your Program

You can compile your program using a C++ compiler such as `g++`.

### Compile

```bash
g++ -std=c++17 sortComparison.cpp -o sortComparison
```

### Run on macOS or Linux

```bash
./sortComparison
```

Make sure your program compiles successfully and completes all required experiments.

---

# 15. Common Mistakes to Avoid

### Mistake 1: Forgetting Pass by Reference

The required function headers include:

```cpp
std::vector<int>& numbers
```

Do not remove the `&`.

The sorting functions must modify the original vector.

### Mistake 2: Reusing an Already Sorted Vector

If Insertion Sort sorts a vector first, do not directly pass that same sorted vector to Merge Sort for the timing comparison.

Use independent copies containing the same original random values.

### Mistake 3: Measuring Extra Operations

Do not include unrelated operations, such as printing or random vector generation, in the sorting execution time.

### Mistake 4: Running Only One Trial

The assignment requires 10 trials for every input size.

A single measurement is not sufficient.

### Mistake 5: Forgetting to Calculate Averages

You must calculate the average execution time for each algorithm and input size.

### Mistake 6: Incorrect Merge Sort Indices

For a vector with N elements, the last valid index is:

```text
N - 1
```

Be careful when working with the starting and ending indices.

### Mistake 7: Reporting Only Theoretical Complexities

Part C requires actual measured execution times.

Writing only O(n²) and O(n log n) does not satisfy the experimental requirements.

---

# 16. Final Submission Checklist

Before submitting your homework, make sure that:

- [ ] I implemented `insertionSort()` using the required function header.
- [ ] I implemented `mergeSort()` using the required function header.
- [ ] Both algorithms sort integers in ascending order.
- [ ] I tested N = 10, 100, 1000, and 10000.
- [ ] Each random vector contains integers between 0 and 999.
- [ ] I performed 10 trials for each input size.
- [ ] I used identical input values for both algorithms in each trial.
- [ ] I measured execution time in milliseconds.
- [ ] I calculated average execution times.
- [ ] I compared the results for small and large N.
- [ ] I explained the relationship between the results and Big O complexity.
- [ ] My source code is named `sortComparison.cpp`.
- [ ] My written results and analysis are in a separate document.
- [ ] My program compiles and runs successfully.

---

# 17. Important Reminders

**Academic Resources**

According to the homework instructions, you may use pseudocode and code provided in the assignment description, the Cormen textbook, and the course Blackboard materials.

No other external sources are allowed for this homework.

**Deadline**

Friday, October 16, 2026, at 11:59 PM.

**Final Note**

The main purpose of this assignment is not only to implement two sorting algorithms but also to understand the difference between their theoretical complexities and practical execution times.

Make sure you understand how each algorithm works before starting the performance experiments.

Pay particular attention to using the same random input for both algorithms, measuring only the sorting time, and calculating the average over all 10 trials.

Review your results carefully before writing your final comparison.

Good luck!
