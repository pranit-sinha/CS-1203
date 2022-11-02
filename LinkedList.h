#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct node{
    int val;
    struct node* next;
} node;

typedef struct node * nodeAddress;

nodeAddress generateLinkedList(int n);
void printLinkedList(nodeAddress head);
void freeLinkedList(nodeAddress head);
int inputSize();

#endif
