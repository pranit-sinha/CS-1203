#include <stdio.h> 
#include <stdlib.h> 
#include "headers/LinkedList.h"
 
nodeAddress chunkReverse(nodeAddress head, int k) {
    nodeAddress prev = head;
    if (head) {
        nodeAddress current = head;
        nodeAddress next = NULL;
        prev = NULL;
        int count = 0;

        while (current && count < k) {
            next            = current->next;
            current->next   = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next) {
            head->next = chunkReverse(next, k);
        }
    }

    return prev;
}

int main (int argc, char** argv) {
    char * sizestring = "Enter size of the list: ";
    char * kstring = "Enter size of chunk: ";
    int n = input(sizestring);
    nodeAddress head = generateLinkedList(n);
    printLinkedList(head);
    int k = input(kstring);
    nodeAddress newHead = chunkReverse(head, k);
    printLinkedList(newHead);
    freeLinkedList(newHead);
	return 0; 
}
