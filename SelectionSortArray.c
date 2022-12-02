#include <stdio.h>
#include <stdlib.h>
#include "headers/Array.h"
#include "headers/Sort.h"

int main (int argc, char** argv) {
    int n = inputSizeArray();
    int a[n];
    fillArray(a, n);
    printArray(a, n);
    selectionSort(a, n);
    printArray(a, n); 
}
