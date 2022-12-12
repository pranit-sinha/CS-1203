#include <stdio.h> 
#include <stdlib.h> 
#include "headers/LinkedList.h"

void selectionSort(nodeAddress head) {
    nodeAddress temp = head;
    while (temp) {
        nodeAddress min    = temp;
        nodeAddress rem    = temp->next;
        while (rem) {
            if (min->val > rem->val) {
                min = rem;
            }
            rem = rem->next;
        }

        int t       = temp->val;
        temp->val   = min->val;
        min->val    = t;
        temp        = temp->next;
    }
}

int main (int argc, char** argv) { 
    int n = input();
    nodeAddress headOfList = generateLinkedList(n);
    selectionSort(headOfList);
    printLinkedList(headOfList);
    freeLinkedList(headOfList);
}

