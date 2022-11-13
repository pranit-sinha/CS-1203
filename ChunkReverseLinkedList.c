#include <stdio.h> 
#include <stdlib.h> 
#include "LinkedList.h"
 
nodeAddress chunkReverse(nodeAddress head, int k) {
    nodeAddress current = head;
    head = NULL;
    int count = 1;
    while (count<=k && current!=NULL) {
        nodeAddress temp = current;
        current = current->next;
        temp->next = head;
        head = temp;
        count++;
    }
    return head;
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

