#include <stdio.h> 
#include <stdlib.h> 
#include "headers/LinkedList.h"
 
int main (int argc, char** argv) { 
    char * string = "Enter size of List: ";
    int n = input(string);
    nodeAddress headOfList = generateLinkedList(n);
    printLinkedList(headOfList);
}

