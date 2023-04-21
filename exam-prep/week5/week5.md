# Linear DS (Queue)

A queue is a linear data structure which follows a particular order in which the operations are performed. The order is **FIFO** (First In First Out). A good example of a queue is any queue of consumers for a resource where the consumer that came first is served first.

## Queue with Array

A queue can be implemented using array. A queue made with an array is called **Array-based Queue**. The advantage of using an array is that it is easy to implement and memory is saved as pointers are not involved. The disadvantage is that the size of the queue needs to be specified in advance and is fixed. Also, insertion and deletion in an array is expensive, because room has to be created for the new elements and to create space, existing elements have to be shifted.

## Queue with Linked List

A queue can be implemented using linked list. A queue made with a linked list is called **Linked List-based Queue**. The advantage of using a linked list is that the size of the queue can grow and shrink on demand. The disadvantage is that it uses more memory than array-based queue because of the storage used by the pointers.

## Circular Queue (with Array)

A circular queue is a queue that uses an array in which the end of the array "wraps around" to the beginning of the array. Circular queues are useful in situations where a non-circular queue would cause the queue to overflow (i.e. the queue would exceed the size limit of the array) even though there are free spaces in the array. Circular queues are also used for process scheduling in operating systems. The advantage of using a circular queue is that the memory is saved as we use the same array space even if we dequeue a value. The disadvantage is that the size of the queue needs to be specified in advance and is fixed.
