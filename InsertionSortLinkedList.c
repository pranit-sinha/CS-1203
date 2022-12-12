#include <stdio.h> 
#include <stdlib.h> 
#include "headers/LinkedList.h"

//nodeAddress cons(int x, nodeAddress tail) {
//    nodeAddress new_head = malloc(sizeof(node));
//    new_head->val = x;
//    new_head->next = tail;
//    return new_head;
//}
//
//void insert(nodeAddress head, int x) {
//    if (head == NULL) {
//        head = cons(x, head);
//    }
//    else if (x <= head->val) {
//        nodeAddress inserted_node = cons(x, head);
//        head->next = inserted_node;
//    }
//    else {
//        insert(x, head->next);
//    }
//}

//void insertNode(nodeAddress n, nodeAddress tail) {
//    if (tail==NULL| n->val <= tail->val) {
//        n->next = tail;
//        tail = n;
//    }
//    else {
//        insertNode(n, tail->next);
//    }
//}
//
//void insertionSort(nodeAddress head) {
//    if (head) {
//        nodeAddress tail = head->next;
//        insertionSort(tail);
//        insertNode(head, tail);
//    }
//}

void insert(nodeAddress node, nodeAddress sorted) {
    if (sorted==NULL || sorted->val >= node->val) {
        node->next = sorted;
        sorted = node;
    }
    else {
        nodeAddress current = sorted;
        while (current->next != NULL && current->next->val < node->val) {
            current = current->next;
        }
        node->next      = current->next;
        current->next   = node;
    }
}

void insertionSort(nodeAddress head) {
    nodeAddress current = head;
    nodeAddress sorted = NULL;
    while (current) {
        nodeAddress next = current->next;
        insert(current, sorted);
        current = next;
    }
    head = sorted;
}
 
int main (int argc, char** argv) {
    int n = input();
    nodeAddress head = generateLinkedList(n);
    printLinkedList(head);
    insertionSort(head);
    printLinkedList(head);
    freeLinkedList(head);
}

