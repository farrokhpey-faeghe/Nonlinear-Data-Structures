# Grade Histogram Practice

This exercise focuses on using **arrays** and **vectors** in C++ to count student grades and generate a text-based histogram.

---

## Problem 1: Grade Histogram Using an Array

Write a C++ program that generates a text-based histogram for quiz grades.

The quiz is graded on a scale from **0 to 5**.

### Your program should:

* Allow the user to enter the grades for a class of students.
* Use an array of size **6** to count how many students received each grade.
* Initialize every element of the array to `0`.
* Use the grade itself as the array index.
* Increase the corresponding array element each time a grade is entered.
* Print the histogram after all grades have been entered.

### Example Input

```text
3, 0, 1, 3, 3, 5, 5, 4, 5, 4
```

### Expected Output

```text
1 grade(s) of 0
1 grade(s) of 1
0 grade(s) of 2
3 grade(s) of 3
2 grade(s) of 4
3 grade(s) of 5
```

---

## Problem 2: Grade Histogram Using a Vector

Write a C++ program that generates a histogram of grades for an assignment.

### Your program should:

* Read each student's grade as an integer.
* Store each valid grade in a `vector`.
* Continue accepting grades until the user enters `-1`.
* Do not store `-1` in the vector.
* After input is complete, scan through the vector.
* Count how many students received each grade from **0 through 5**.
* Print the histogram to the console.

### Example Input

```text
3
0
1
3
3
5
5
4
5
4
-1
```

### Vector Contents

```text
3, 0, 1, 3, 3, 5, 5, 4, 5, 4
```

### Expected Output

```text
1 grade(s) of 0
1 grade(s) of 1
0 grade(s) of 2
3 grade(s) of 3
2 grade(s) of 4
3 grade(s) of 5
```
