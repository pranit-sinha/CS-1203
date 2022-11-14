#include <stdio.h> 
#include <stdlib.h> 
#include "headers/LinkedList.h"

int main (int argc, char** argv) { 
    int n = inputSize();
    nodeAddress headOfList = generateLinkedList(n);
    printLinkedList(headOfList);
    freeLinkedList(headOfList);
}

