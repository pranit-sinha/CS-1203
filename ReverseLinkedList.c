#include <stdio.h> 
#include <stdlib.h> 

typedef struct node{
    int val;
    struct node* next;
} node;

typedef struct node * nodeAddress;

nodeAddress generateLinkedList(int n) {
    nodeAddress head = NULL;
    if(n>0) {
        head = malloc(sizeof(node));
        printf("Enter element in position 1. ");
        scanf("%d", &head->val);
        head->next = NULL;
        nodeAddress current = head;
        for (int i = 1; i<n; i++) {
            current->next = malloc(sizeof(node));
            current = current->next;
            printf("Enter element in position %d. ", (i+1));
            scanf("%d", &current->val);
            current->next = NULL;
        }
    }
    return head;
}

void chunkReverse (nodeAddress head, k) {}

void printLinkedList(nodeAddress head) {
    nodeAddress c;
    for (c = head ; c != NULL; c = c->next) {
        printf(c==head?"%d":", %d", c->val);
    }
}

int main (int argc, char** argv) { 
    printf("Enter number of list elements.");
    scanf("%d",&n);
    nodeAddress headOfList = generateLinkedList();
    printLinkedList(headOfList);
    printf("Enter size of chunks within which elements will be reversed.");
    int k;
    scanf("%d",&k);
    chunkReverse(headOfList, k);
    printLinkedList(head);
}

