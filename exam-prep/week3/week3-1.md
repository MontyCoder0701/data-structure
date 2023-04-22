# Pointer, Reference

## Pointer

- A pointer is a variable that holds the memory address of another variable.
- A pointer needs to be dereferenced with the `*` operator to access the memory location it points to.

## Reference

- A reference variable is an alias, that is, another name for an already existing variable.
- A reference, like a pointer, is also implemented by storing the address of an object.
- Reference is declared by using `&` operator.

## Example

```c
int i = 3;

// A pointer to variable i or "stores the address of i"
int *ptr = &i;

// A reference (or alias) for i.
int &ref = i;
```
