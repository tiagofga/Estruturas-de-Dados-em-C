# List — Dynamic Sequential List

[Português](../Lista.md) | **English**

## Overview

Implementation of a dynamic sequential list in C. The elements are stored in a contiguous array that can grow when needed.

This structure is appropriate when indexed access and simple sequential storage are desired.

---

## Main operations

Typical operations include:

- create and destroy the list;
- insert elements;
- remove elements;
- search for values;
- access elements by position;
- sort values;
- inspect size and capacity.

---

## Complexity summary

| Operation | Complexity |
|-----------|------------|
| Access by index | O(1) |
| Insert at the end | O(1) amortized |
| Insert in the middle | O(n) |
| Remove from the middle | O(n) |
| Linear search | O(n) |
| Binary search | O(log n), requires sorted data |
| Sorting | Depends on the selected algorithm |

---

## Advantages

- Simple memory layout.
- Efficient indexed access.
- Good cache locality.
- Useful for teaching array-based dynamic structures.

## Limitations

- Insertions and removals in the middle require shifting elements.
- Resizing may require memory reallocation.
- It is less flexible than linked structures for frequent middle insertions/removals.

---

Back to the [documentation index](./README.md).
