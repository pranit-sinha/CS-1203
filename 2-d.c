#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h>
#include <time.h>
 
typedef struct node{
    int val;
    int k;
    struct node * next;
    struct node * nextk;
} node;

typedef struct node * NodeAddress;

NodeAddress arrayToLLWithNextK(int *a, int n) {
    NodeAddress head = NULL;
    srand(time(NULL));
    if(n>0) {
        head = malloc(sizeof(node));
        head->val = a[0];
        head->next = NULL;
        head->k = rand() % (4) + 2;     // We use the following formula to get random numbers in a particular range: rand() % (max_number + 1 - minimum_number) + minimum_number
        NodeAddress current = head;
        for (int i = 1; i<n; i++) {
            current->next = malloc(sizeof(node));
            current = current->next;
            current->val = a[i];
            current->k = rand() % (4) + 2; 
            current->next = NULL;
        }
        current = head;
        for (int i = 0; i<n; i++) {
            NodeAddress nextk_j = current;
            for(int j=1;j<current->k;j++) {
                if(nextk_j->next==NULL) {
                    nextk_j->next=NULL;
                }
                else {
                    nextk_j = nextk_j->next;
                }
            }
            current->nextk = nextk_j->next;
            current = current->next;
        }
    }
    return head;
}

NodeAddress reverseLLWithNextK (NodeAddress head) {
    NodeAddress current = head;
    head = NULL;
    while (current!=NULL) {
        NodeAddress temp = current;
        current = current->next;
        temp->next = head;
        head = temp;
    }
    current = head;
    while (current) {
        NodeAddress nextk_j = current;
        for(int j=1;j<current->k;j++) {
            if(nextk_j->next==NULL) {
                nextk_j->next=NULL;
            }
            else {
                nextk_j = nextk_j->next;
            }
        }
        current->nextk = nextk_j->next;
        current = current->next;
    }
    return head;
}

void printLinkedList(NodeAddress head) {
    NodeAddress c;
    for (c = head ; c != NULL; c = c->next) {
        printf(c==head?"%d":", %d", c->val);
    }
    printf("\n");
    for (c = head ; c != NULL; c = c->next) {
        printf(c==head?"%d":", %d", c->k);
    }
    printf("\n");

    for (c = head ; c != NULL; c = c->next) {
        printf(c==head?"%d":", %d", ((intptr_t)(c->next)%1000));
    }
    printf("\n");

    for (c = head ; c != NULL; c = c->next) {
        printf(c==head?"%d":", %d", ((intptr_t)(c->nextk)%1000));
    }
    printf("\n");
}

int main (int argc, char** argv) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n]; 
    for (int i = 0; i < n; i++) {
        printf("Enter element in position %d: ", i);
        scanf("%d", &a[i]);
    }
    NodeAddress head = arrayToLLWithNextK(a, n);
    printLinkedList(head);
    NodeAddress newhead = reverseLLWithNextK(head);
    printLinkedList(newhead);
}

