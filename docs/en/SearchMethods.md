# Search Methods for Arrays

[Português](../MetodosBusca.md) | **English**

## Overview

This module implements and compares search algorithms for arrays. Some methods work on any array, while others require sorted data.

---

## Implemented methods

| Method | Requirement | Complexity |
|--------|-------------|------------|
| Linear search | Any array | O(n) |
| Binary search | Sorted array | O(log n) |
| Jump search | Sorted array | O(√n) |
| Interpolation search | Sorted and uniformly distributed data | Average O(log log n), worst O(n) |
| Exponential search | Sorted array | O(log n) |

---

## Notes

Binary, jump, interpolation, and exponential search assume the input array is sorted. Applying them to unsorted data produces incorrect results.

---

Back to the [documentation index](./README.md).
