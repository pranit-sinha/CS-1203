#include <stdio.h> 
#include <stdlib.h> 

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

void returnSmallestNum(int *maxHeap, int n) {
    int min = maxHeap[n/2];
    for (int i = n/2; i<n; i++) {
        if (min > maxHeap[i]) {
            min = maxHeap[i];
        }
    }
    printf("The smallest number is %d\n", min);
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
    returnSmallestNum(a, n);
}
