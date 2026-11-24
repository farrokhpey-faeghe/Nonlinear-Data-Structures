# Homework 9 – Elementary Graph Algorithms

**Course:** EECS 2510 – Non-Linear Data Structures  
**Semester:** Fall 2026  
**Topic:** Breadth-First Search (BFS)  
**Language:** C++  
**Due Date:** Sunday, November 29, 2026, at 11:59 PM

---

## 1. Overview

The objective of this assignment is to implement Breadth-First Search
(BFS) on an undirected graph in C++.

You will read graph information from an input file, construct a graph,
perform BFS from a user-selected starting node, and determine the
shortest-path distance from the starting node to every other node.

This assignment focuses on understanding graph representation,
graph traversal, and shortest-path distances in unweighted graphs.

## 2. Learning Objectives

By completing this assignment, you should be able to:

- Understand the fundamental concepts of graphs.
- Read and interpret an adjacency matrix.
- Represent an undirected graph using an appropriate data structure.
- Understand how Breadth-First Search works.
- Understand the role of a queue in BFS.
- Track visited and unvisited nodes.
- Determine shortest-path distances in an unweighted graph.
- Handle disconnected graphs and unreachable nodes.
- Test and validate a graph traversal algorithm.

## 3. Graph Terminology

Before starting the assignment, review the following concepts:

| Term | Description |
|---|---|
| Vertex (Node) | An individual element of a graph. |
| Edge | A connection between two vertices. |
| Undirected Graph | A graph whose edges have no direction. |
| Adjacent Nodes | Nodes that are directly connected by an edge. |
| Path | A sequence of vertices connected by edges. |
| Cycle | A path that starts and ends at the same vertex without repeating intermediate vertices. |
| Connected Graph | A graph in which every vertex is reachable from every other vertex. |
| Disconnected Graph | A graph containing vertices that cannot all reach one another. |
| Shortest Path | A path containing the minimum number of edges between two vertices in an unweighted graph. |

## 4. Input File Format

Your program must read graph information from a file named `input.txt`.

The file contains three sections:

1. An integer `N`, representing the number of nodes.
2. The next `N` lines contain unique node names.
3. The next `N` lines contain an `N x N` adjacency matrix.

Each node name is a one- or two-character string.

Each entry in the adjacency matrix is either `0` or `1`.

- `0`: No edge exists between the corresponding nodes.
- `1`: An edge exists between the corresponding nodes.

Because the graph is undirected:

- The adjacency matrix is symmetric.
- All diagonal entries are zero.
- The graph does not contain self-loops.

Make sure you understand the relationship between the order of the
node names and the rows and columns of the adjacency matrix.

## 5. Graph Representation

There are several ways to represent a graph in C++.

### Adjacency Matrix

An adjacency matrix is a two-dimensional structure that represents
connections between vertices.

Each row and column corresponds to a vertex.

Consider the following questions:

- What does each matrix entry represent?
- Why is the matrix symmetric for an undirected graph?
- How can you identify the neighbors of a particular node?
- How much memory does an adjacency matrix require?

### Adjacency List

An adjacency list stores the neighboring vertices of each vertex.

Consider the following questions:

- How can you represent node names?
- How can you store the neighbors of each node?
- How can you prevent duplicate edges?
- How can you represent a node that has no neighbors?

You may use any appropriate graph representation that satisfies
the assignment requirements.

## 6. Breadth-First Search (BFS)

Breadth-First Search is a graph traversal algorithm that explores
vertices level by level, starting from a selected vertex.

BFS explores vertices in increasing order of their shortest-path
distance from the starting vertex.

Unlike Depth-First Search (DFS), BFS explores nearby vertices
before exploring vertices that are farther away.

Before implementing BFS, make sure you understand:

- How graph traversal works.
- The First-In, First-Out (FIFO) principle.
- The relationship between BFS and queues.
- The importance of tracking visited vertices.
- How BFS behaves when a graph contains cycles.
- How BFS behaves when a graph is disconnected.

### BFS vs. DFS

| Feature | BFS | DFS |
|---|---|---|
| Traversal approach | Level by level | Depth-oriented |
| Common data structure | Queue | Stack |
| Shortest path in an unweighted graph | Guaranteed | Not guaranteed |
| Exploration strategy | Nearest vertices first | Explore a branch before backtracking |

## 7. Understanding Queues

A queue is a linear data structure that follows the FIFO
(First-In, First-Out) principle.

The element inserted first is the element removed first.

Common queue operations include:

| Operation | Description |
|---|---|
| `push()` | Inserts an element into the queue. |
| `pop()` | Removes the front element. |
| `front()` | Accesses the front element. |
| `empty()` | Checks whether the queue is empty. |

Think about why the FIFO principle is appropriate for
level-by-level graph traversal.

## 8. Visited Nodes

Graphs may contain multiple paths between vertices and may
also contain cycles.

Tracking visited nodes is important to prevent unnecessary
or repeated processing of vertices.

Consider the following questions:

- What happens if a graph contains a cycle?
- What happens if multiple vertices share the same neighbor?
- Why should a vertex not be processed repeatedly?
- When should a vertex be considered visited?

You should determine an appropriate way to maintain the
visited status of each vertex.

## 9. Distance Between Nodes

In this assignment, distance is defined as the minimum number
of edges between the starting vertex and another vertex.

Remember:

- The distance from the starting vertex to itself is zero.
- Every edge contributes one unit of distance.
- Distance refers to the shortest path, not an arbitrary path.
- A vertex that cannot be reached must be reported as
  `not reachable`.

BFS guarantees shortest-path distances in an unweighted graph.

Consider how the level-by-level exploration of BFS relates
to the shortest-path distance.

## 10. Useful C++ Standard Library Components

The following C++ Standard Library components may be useful
when designing your program.

| Component | Purpose |
|---|---|
| `std::string` | Represents node names. |
| `std::ifstream` | Reads information from an input file. |
| `std::vector` | Stores collections of elements. |
| `std::queue` | Supports FIFO operations. |
| `std::unordered_map` | Associates keys with values. |
| `std::unordered_set` | Stores unique elements. |

The assignment also suggests the following structure as one
possible representation of an adjacency list:

`std::unordered_map<std::string, std::unordered_set<std::string>>`

You are not required to use all of these components.
Choose data structures that are appropriate for your design.

## 11. Program Requirements

Your program must:

1. Read graph information from `input.txt`.
2. Construct an undirected graph.
3. Prompt the user to enter a starting node.
4. Perform BFS from the selected starting node.
5. Display the BFS traversal order on a single line.
6. Display the distance from the starting node to every node.
7. Report unreachable nodes as `not reachable`.

Your program should work with different valid input graphs,
not only the example provided in the assignment.

## 12. Expected Output Format

Follow the output format specified in the assignment:

    Enter a node name to start BFS:
    BFS traversal order: <node1> <node2> ...
    Distances from <starting node>:
    <node name>: <distance>

For unreachable vertices, display:

    <node name>: not reachable

The traversal order may depend on the order in which
neighboring vertices are processed.

Different valid BFS traversal orders are possible when
multiple vertices are at the same distance from the
starting vertex.

However, shortest-path distances must remain correct.

## 13. Suggested Development Approach

Before writing your complete program, divide the assignment
into smaller tasks:

- Understand the input file format.
- Design an appropriate graph representation.
- Verify that the graph information is read correctly.
- Review the properties of BFS.
- Determine how to maintain visited status and distances.
- Design the required output.
- Test individual parts of your program.
- Test the complete program using different graphs.

Avoid implementing everything at once. Test each component
before moving to the next part.

## 14. Compilation and Execution

Keep your source file and input file in the same directory.

### Directory Structure

    Homework9/
    ├── BFSGraph.cpp
    ├── input.txt
    └── README.md

### macOS and Linux

Compile the program:

```bash
g++ -std=c++17 -Wall -Wextra BFSGraph.cpp -o BFSGraph
```

Run the program:

```bash
./BFSGraph
```

### Windows (MinGW)

Compile the program:

```bash
g++ -std=c++17 -Wall -Wextra BFSGraph.cpp -o BFSGraph.exe
```

Run the program:

```powershell
.\BFSGraph.exe
```

Make sure `input.txt` is available in the current working
directory when executing the program.

C++17 is suggested for these compilation examples.
Use any compiler standard required by your instructor.

## 15. Testing and Validation

Do not rely exclusively on the sample graph provided
in the assignment.

Create your own test cases to verify that your program
works under different conditions.

| Test Case | Purpose |
|---|---|
| Single-node graph | Verify basic traversal behavior. |
| Two connected nodes | Verify simple graph connectivity. |
| Linear graph | Verify traversal across multiple levels. |
| Graph with cycles | Verify visited-node handling. |
| Disconnected graph | Verify unreachable-node handling. |
| Isolated vertex | Verify behavior when a node has no neighbors. |
| Complete graph | Verify behavior with many connections. |
| Different starting nodes | Verify that traversal depends on the selected source. |
| Two-character node names | Verify that node names are read correctly. |

For each test case:

1. Draw the graph on paper.
2. Determine its adjacency matrix.
3. Predict the expected BFS behavior manually.
4. Create the corresponding input file.
5. Run your program.
6. Compare the actual and expected results.

Your instructor will test your program using an additional
graph that is not provided in the assignment.

## 16. Common Mistakes

Pay attention to the following potential issues:

- Reading an incorrect number of matrix entries.
- Confusing node names with matrix indices.
- Incorrectly representing undirected edges.
- Creating duplicate edges.
- Processing the same vertex multiple times.
- Confusing BFS with DFS.
- Using incorrect shortest-path distances.
- Assuming every vertex is reachable.
- Forgetting to include isolated vertices.
- Hardcoding the sample graph.
- Hardcoding the starting vertex.
- Hardcoding the expected output.
- Testing only one input graph.
- Using an incorrect source file name.

## 17. Questions to Consider

Before submitting your assignment, make sure you can answer
the following questions:

1. Why is an adjacency matrix symmetric for an undirected graph?
2. What is the difference between an adjacency matrix and an adjacency list?
3. Why does BFS use a queue instead of a stack?
4. Why is tracking visited vertices necessary?
5. What happens when BFS encounters a cycle?
6. How does BFS determine shortest-path distances?
7. What happens when the starting vertex has no neighbors?
8. Can BFS produce different valid traversal orders?
9. What happens when a graph contains disconnected components?
10. What is the time complexity of BFS with an adjacency list?
11. How does using an adjacency matrix affect traversal complexity?

These questions are intended to help you understand the
algorithm before implementing your own solution.

## 18. Submission Checklist

- [ ] My program compiles successfully.
- [ ] My program reads `input.txt` correctly.
- [ ] My program supports one- and two-character node names.
- [ ] My graph representation supports undirected edges.
- [ ] My program accepts a user-selected starting node.
- [ ] My BFS traversal works correctly.
- [ ] My program does not process vertices repeatedly.
- [ ] My program calculates shortest-path distances correctly.
- [ ] My program reports unreachable vertices.
- [ ] My program handles disconnected graphs.
- [ ] My program handles isolated vertices.
- [ ] My program has been tested with multiple input graphs.
- [ ] My output follows the required format.
- [ ] My source file is named `BFSGraph.cpp`.

## 19. Submission Instructions

Submit your C++ source file using the following exact filename:

    BFSGraph.cpp

**Deadline:** Sunday, November 29, 2026, at 11:59 PM.

## 20. Permitted Resources

According to the assignment instructions, you may use
pseudocode or code from:

- The CLRS textbook.
- Class lecture slides.

No other external sources are permitted for this assignment.

---

## Note

This README is intended to clarify the assignment requirements
and review the relevant data structures and graph concepts.

It does not provide a complete implementation, pseudocode,
or solutions to the assignment.

Students are responsible for designing, implementing, testing,
and understanding their own solutions.
