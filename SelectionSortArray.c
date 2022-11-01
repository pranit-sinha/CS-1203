#include <stdio.h> 
#include <stdlib.h> 

void fillArray(int * a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element in position %d: ", i);
        scanf("%d", &a[i]);
    }
}

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

void printArray(int * a, int n) {
    printf("%d", a[0]);
    for (int i = 1; i<n; i++) {
        printf(", %d", a[i]);
    }
    printf("\n");
}

int main (int argc, char** argv) {
    int n;
    printf("Enter number of elements in array. ");
    scanf("%d",&n);
    int a[n];
    fillArray(a, n);
    printArray(a, n);
    selectionSort(a, n);
    printArray(a, n);
}
