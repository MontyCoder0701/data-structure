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
int myAge = 43;     // Variable declaration
int* ptr = &myAge;  // Pointer declaration

// Reference: Output the memory address of myAge with the pointer (0x7ffe5367e044)
printf("%p\n", ptr);

// Dereference: Output the value of myAge with the pointer (43)
printf("%d\n", *ptr);
```
