# Queue — Circular FIFO Queue

[Português](../Fila.md) | **English**

## Overview

Implementation of a circular queue in C. A queue follows the **FIFO** principle: first in, first out.

The circular representation reuses array positions after elements are removed from the front.

---

## Main operations

- create and destroy the queue;
- enqueue an element;
- dequeue an element;
- inspect the front element;
- check whether the queue is empty or full;
- inspect the current size.

---

## Complexity summary

| Operation | Complexity |
|-----------|------------|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Peek front | O(1) |
| Empty/full check | O(1) |

---

## Use cases

Queues are commonly used in:

- scheduling;
- buffering;
- breadth-first search (BFS);
- producer-consumer systems;
- simulations.

---

Back to the [documentation index](./README.md).
