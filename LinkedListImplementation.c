#include <stdio.h> 
#include <stdlib.h> 
#include "LinkedList.h"
 
int main (int argc, char** argv) { 
    char * string = "Enter size of string: ";
    int n = input(string);
    nodeAddress headOfList = generateLinkedList(n);
    printLinkedList(headOfList);
}

