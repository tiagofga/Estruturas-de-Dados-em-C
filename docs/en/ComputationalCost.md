# Computational Cost and Complexity

[Português](../CustoComputacional.md) | **English**

## Overview

Computational cost measures how an algorithm consumes resources as the input size grows. The two most common dimensions are:

- **time complexity**: how the number of operations grows;
- **space complexity**: how memory usage grows.

---

## Common growth rates

| Notation | Name | Example |
|----------|------|---------|
| O(1) | Constant | Accessing an array position |
| O(log n) | Logarithmic | Binary search |
| O(n) | Linear | Linear search |
| O(n log n) | Linearithmic | Merge sort, heap sort |
| O(n²) | Quadratic | Bubble sort, selection sort |
| O(2ⁿ) | Exponential | Exhaustive combinatorial search |

---

## Why it matters

Complexity analysis helps compare algorithms independently from a specific machine, compiler, or input file. It is essential for choosing appropriate data structures and algorithms.

---

Back to the [documentation index](./README.md).
