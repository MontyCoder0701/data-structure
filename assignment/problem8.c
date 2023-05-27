#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
} treeNodeType;

void DescendingOrder(treeNodeType* T) {
    if (T == NULL) {
        return;
    }
    DescendingOrder(T->right);
    printf("%d ", T->data);
    DescendingOrder(T->left);
}

int main() {
    treeNodeType* root = (treeNodeType*)malloc(sizeof(treeNodeType));
    root->data = 4;
    root->left = (treeNodeType*)malloc(sizeof(treeNodeType));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (treeNodeType*)malloc(sizeof(treeNodeType));
    root->right->data = 6;
    root->right->left = NULL;
    root->right->right = NULL;

    DescendingOrder(root);

    return 0;
}