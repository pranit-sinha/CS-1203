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

nodeAddress reverseLinkedList(nodeAddress head) {
    nodeAddress current = head;
    head = NULL;
    while (current!=NULL) {
        nodeAddress temp = current;
        current = current->next;
        temp-> next = head;
        head = temp;
    }
    return head;
}

void printLinkedList(nodeAddress head) {
    nodeAddress c;
    for (c = head ; c != NULL; c = c->next) {
        printf(c==head?"%d":", %d", c->val);
    }
    printf("\n");
}

void freeLinkedList(nodeAddress head) {
    nodeAddress previous;
    while (head) {
        previous = head;
        head = head->next;
        free(previous);
    }
}

int main (int argc, char** argv) { 
    int n;
    printf("Enter number of list elements: ");
    scanf("%d",&n);
    nodeAddress headOfList = generateLinkedList(n);
    printLinkedList(headOfList);
    nodeAddress newHead = reverseLinkedList(headOfList);
    printLinkedList(newHead);
    freeLinkedList(newHead);
}

