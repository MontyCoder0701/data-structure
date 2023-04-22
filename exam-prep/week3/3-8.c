#include <stdio.h>
#include <stdlib.h>

typedef struct charNode
{
    char ch;
    struct charNode *p; // dereferencing p will give you the value to a struct charNode
} nodeType;             // nodeType is a type name for struct charNode

int main()
{
    nodeType *node1, *node2;

    node1 = (nodeType *)malloc(sizeof(nodeType)); // allocate memory for node1
    node1->ch = 'X';                              // assign 'X' to node1->ch
    node1->p = NULL;                              // assign NULL to node1->p (no next node)

    node2 = (nodeType *)malloc(sizeof(nodeType));
    node2->ch = 'Z';
    node2->p = NULL;
}
