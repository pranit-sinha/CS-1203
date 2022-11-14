#include <stdio.h>
#include <stdlib.h>
#include "headers/Array.h"

int findAddressOfMax (int * a, int n) {
    int * maxAddress = NULL;
    if (n>=1) { 
        maxAddress = a;
        for (int i = 1; i<n; i++) {
            if ( *((int *)(a+i)) > *maxAddress ) {
                maxAddress = (int*)(a+i);
            }
        }
    return maxAddress;
    }
}

void selectionSort (int * a, int n) {
    int * maxAdd;
    int temp;
    for (int i = n; i>1; i=i-1) {
        maxAdd  = findAddressOfMax(a, i);
        temp = *maxAdd;
       // *maxAdd   = a[i-1];
       // a[i-1]  = temp;
        printf("The max element is %p\n", maxAdd);
       // printf("The max element is %d\n", temp);
    }
}

int main (int argc, char** argv) {
    int n = inputSizeArray();
    int a[n];
    fillArray(a, n);
    printArray(a, n);
    selectionSort(a, n);
    printArray(a, n); }
