#include <stdio.h> 
#include <stdlib.h> 
#include "Array.h"

struct node {
    int val;
    struct node * left;
    struct node * right;
};

typedef struct node * nodeAddress;

void generateBstFromArray(a, n) {
    nodeAddress root = NULL;
    int current = 0;
    if (n>0) {
        root = a[current];
    }
}
 
int main (int argc, char** argv) { 
    int n = inputSizeArray();
    int a[n];
    void fillArray(a, n);
    generateBstFromArray(a, n);
    printBST;
}

