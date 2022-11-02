#include <stdio.h> 
#include <stdlib.h> 
#include "LinkedList.h"

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
