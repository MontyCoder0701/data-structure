# Linear DS (Stack)

A stack is a linear data structure which follows a particular order in which the operations are performed. The order is  **LIFO**  (Last In First Out). A good example of a stack is any pile of objects like a deck of cards or a pile of plates, etc.

## Stack with Array

A stack can be implemented using array. A stack made with an array is called  **Array-based Stack**. The advantage of using an array is that it is easy to implement and memory is saved as pointers are not involved. The disadvantage is that the size of the stack needs to be specified in advance and is fixed. Also, insertion and deletion in an array is expensive, because room has to be created for the new elements and to create space, existing elements have to be shifted.

![image](https://user-images.githubusercontent.com/104475739/233637651-a762e019-c3d2-4cc0-9c9e-c979eb8348bf.png)


## Stack with Linked List

A stack can be implemented using linked list. A stack made with a linked list is called  **Linked List-based Stack**. The advantage of using a linked list is that the size of the stack can grow and shrink on demand. The disadvantage is that it uses more memory than array-based stack because of the storage used by the pointers.

![image](https://user-images.githubusercontent.com/104475739/233638010-cdd97ca3-30f8-447b-88b2-2908a92a79ec.png)
