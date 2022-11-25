#include <stdio.h>
#include <stdlib.h>
#include "headers/Array.h"

int * findAddressOfMax (int * a, int n) {
    int * maxAddress = NULL;
    if (n>=1) { 
        maxAddress = a;
        for (int i = 0; i<n; i++) {
            if ( *(a+i) > *maxAddress ) {
                maxAddress = (a+i);
            }
        }
    return maxAddress;
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort (int * a, int n) {
    int * maxAdd;
    int temp;
    for (int i = n; i>0; i=i-1) {
        maxAdd  = findAddressOfMax(a, i);
        swap(maxAdd, &a[i-1]);
    }
}

int main (int argc, char** argv) {
    int n = inputSizeArray();
    int a[n];
    fillArray(a, n);
    printArray(a, n);
    selectionSort(a, n);
    printArray(a, n); 
}
