# Static vs. Dynamic Structures

[Português](../EstaticoVsDinamico.md) | **English**

## Overview

Lists, queues, and stacks can be implemented using either fixed-size static storage or dynamically allocated memory.

---

## Static implementation

A static implementation uses a fixed-capacity array.

### Advantages

- Simpler implementation.
- Predictable memory usage.
- No runtime allocation after initialization.

### Limitations

- Capacity must be known in advance.
- The structure may waste memory if underused.
- It cannot grow beyond the predefined limit.

---

## Dynamic implementation

A dynamic implementation allocates and resizes memory at runtime.

### Advantages

- More flexible capacity.
- Better suited for inputs of unknown size.
- Can grow as needed.

### Limitations

- Requires careful memory management.
- May involve reallocation costs.
- More error cases must be handled.

---

## Comparison

| Aspect | Static | Dynamic |
|--------|--------|---------|
| Capacity | Fixed | Can grow |
| Memory control | Simple | More complex |
| Flexibility | Lower | Higher |
| Allocation cost | Usually lower | May require reallocations |
| Teaching value | Good for fundamentals | Good for memory management |

---

Back to the [documentation index](./README.md).
