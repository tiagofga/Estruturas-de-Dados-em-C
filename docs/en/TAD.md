# ADT — Abstract Data Type

[Português](../TAD.md) | **English**

## Overview

An **Abstract Data Type (ADT)** defines a data model by its behavior: the operations available, their expected effects, and their constraints. The internal representation is an implementation detail.

In C, an ADT is commonly represented by:

- a header file (`.h`) that exposes the public interface;
- a source file (`.c`) that implements the operations;
- documentation explaining the expected behavior and complexity.

---

## Main idea

An ADT separates:

| Aspect | Description |
|--------|-------------|
| Interface | What operations are available |
| Implementation | How data is stored and manipulated |
| User code | Uses the operations without depending on internal details |

---

## Example

A list ADT may provide operations such as:

```c
lista_inserir(...);
lista_remover(...);
lista_buscar(...);
lista_tamanho(...);
```

The user of the list does not need to know whether the implementation uses an array, a linked list, or another structure.

---

## Educational note

Some modules in this repository expose the `struct` fields directly to keep the implementation transparent for teaching purposes. In production-oriented C code, opaque pointers are often preferred to enforce encapsulation.

---

Back to the [documentation index](./README.md).
