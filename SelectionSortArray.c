#include "Array.h"

int findAddressOfMax (int * a, int n) {
    int * max = NULL;
    if (n>=1) { 
        max = a;
        for (int i = 1; i<n; i++) {
            if ( *(a+i) > *(a+max) ) {
                max = i;
            }
    }
    return max;
}

void selectionSort (int * a, int n) {
    int max, temp;
    for (int i = n; i>1; i=i-1) {
        max     = findAddressofMax(a, i);
        temp    = a[max];
        a[max]  = a[i-1];
        a[i-1]  = temp;
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
