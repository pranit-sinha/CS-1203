#include <stdio.h> 
#include <stdlib.h> 
#include "headers/LinkedList.h"

nodeAddress reverseLinkedList(nodeAddress head) {
    nodeAddress current = head;
    head = NULL;
    while (current!=NULL) {
        nodeAddress temp = current;
        current = current->next;
        temp->next = head;
        head = temp;
    }
    return head;
}

int main (int argc, char** argv) { 
    char * string = "Enter size of the list: ";
    int n = input(string);
    nodeAddress headOfList = generateLinkedList(n);
    printLinkedList(headOfList);
    nodeAddress newHead = reverseLinkedList(headOfList);
    printLinkedList(newHead);
    freeLinkedList(newHead);
}

