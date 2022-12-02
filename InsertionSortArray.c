#include <stdio.h> 
#include <stdlib.h> 
#include "headers/Array.h"

void insertionSort(int * a, int n) {
    for (int i = 1; i<n; i++) {
        for (int j=i; j>0 && a[j-1] > a[j]; j--) {
            int temp = a[j];
            a[j]     = a[j-1];
            a[j-1]   = temp;
        }
    }
}
 
int main (int argc, char** argv) { 
    int n = inputSizeArray();
    int a[n];
    fillArray(a, n);
    printArray(a, n);
    insertionSort(a, n);
    printArray(a, n);
}

