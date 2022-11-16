#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct node{
    int val;
    struct node * next;
    struct node * next2;
} node;

typedef struct node * NodeAddress;
 
NodeAddress arrayToLLWithNext2(int *a, int n) {
    NodeAddress head = NULL;
    if(n>0) {
        head = malloc(sizeof(node));
        head->val = a[0];
        head->next = NULL;
        NodeAddress current = head;
        for (int i = 1; i<n; i++) {
            current->next = malloc(sizeof(node));
            current = current->next;
            current->val = a[i];
            current->next = NULL;
        }
        current = head;
        for (int i = 1; i<n-1; i++) {
            current->next2 = (current->next)->next;
            current = current->next;
        }
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
        printf(c==head?"%d":", %d", c->next);
    }
    printf("\n");

    for (c = head ; c != NULL; c = c->next) {
        printf(c==head?"%d":", %d", c->next2);
    }
    printf("\n");
}

NodeAddress reverseLLWithNext2(NodeAddress head) {
    NodeAddress current = head;
    head = NULL;
    NodeAddress prev = NULL;
    while (current!=NULL) {
        NodeAddress temp = current;
        current = current->next;
        temp->next = head;
        temp->next2 = prev;
        prev = head;
        head = temp;
    }
    return head;
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
    NodeAddress head = arrayToLLWithNext2(a, n);
    printLinkedList(head);
    NodeAddress newHead =reverseLLWithNext2(head);
    printLinkedList(newHead);
}

