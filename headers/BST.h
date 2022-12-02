#ifndef BST_H_
#define BST_H_

struct node {
    int val;
    struct node * left;
    struct node * right;
};

typedef struct node * nodeAddress;

nodeAddress generateBSTFromArray(int *arr, int a, int b);
void printBST(nodeAddress root);

#endif
