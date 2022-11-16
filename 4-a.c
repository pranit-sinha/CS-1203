#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

/*
    AUXILIARY FUNCTIONS HERE
    +
    +
    +
    +
    +
*/

void fillArray(int * a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element in position %d: ", i);
        scanf("%d", &a[i]);
    }
}

void printArray(int * a, int n) {
    printf("%d", a[0]);
    for (int i = 1; i<n; i++) {
        printf(", %d", a[i]);
    }
    printf("\n");
}

int inputSizeArray() {
    int n;
    printf("Enter number of elements in array. ");
    scanf("%d",&n);
    return n;
}

/*
    +
    +
    +
    +
    +
    HEAP RELATED FUNCTIONS AFTER HERE
*/
 
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

void thirdLargestNum(int *maxHeap, int n) {
    int i = extractMax(maxHeap, n);
    int j = extractMax(maxHeap, n);
    if (i==-INFINITY || j==-INFINITY) {
        return;
    }
    printf("The third largest number is %d\n", extractMax(maxHeap, n));
}

void buildMaxHeap(int *a, int n)  {
    int heapsize = n;
    for (int i = (n-1)/2; i>=0; i--) {
        maxHeapify(a, i, n);
    }
}

int main (int argc, char** argv) { 
	int n = inputSizeArray();
    int a[n];
    fillArray(a, n);
    buildMaxHeap(a, n);
    thirdLargestNum(a, n);
}

