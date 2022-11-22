#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include "headers/Array.h"

void maxHeapify(int *maxHeap, int i, int n) {
    int left    = 2*i+1;
    int right   = 2*i+2;
    int largest = i;
    if (left < n && maxHeap[left] > maxHeap[i]) {
        largest = left;
    }
    if (right<n && maxHeap[right] > maxHeap[largest]) {
        largest = right;
    }
    if (largest!=i) {
        int temp            = maxHeap[i];
        maxHeap[i]          = maxHeap[largest] ;
        maxHeap[largest]    = temp;
        maxHeapify(maxHeap, largest, n);
    }
}

int extractMax(int *maxHeap, int n) {
    if (n<1) {
        printf("Heap underflow\n");
        return -INFINITY;
    }
    int max = maxHeap[0];
    maxHeap[0] = maxHeap[n-1];
    n = n - 1;
    maxHeapify(maxHeap, 0, n);
    return max;
}

void buildMaxHeap(int *a, int n)  {
    int heapsize = n;
    for (int i = (n-1)/2; i>=0; i--) {
        maxHeapify(a, i, n);
    }
}

void heapsort(int *a, int n) {
    for (int i = n/2-1; i>=0; i--) {
        maxHeapify(a, n, i);
    }
    int temp;
    for (int i = n-1; i>=0; i--) {
        //swap(&arr[0], &arr[i]);
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        maxHeapify(a, i, 0);
    }
}

int main (int argc, char** argv) { 
	int n = inputSizeArray();
    int a[n];
    fillArray(a, n);
    buildMaxHeap(a, n);
    printArray(a, n);
    heapsort(a, n);
    printArray(a, n);
}
