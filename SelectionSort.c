#include <stdio.h> 
#include <stdlib.h> 

int * generateArray(int n) {
    int a[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element in position %d: ", i);
        scanf("%d", &a[i]);
    }
    return a;
}

void selectionSort (int * a, int n) {
    int max, temp;
    for (int i = n; i>1; i=i-1) {
        max     = findIndexOfMax(a, i);
        temp    = a[max];
        a[max]  = a[i-1];
        a[i-1]  = temp;
    }
}

int findIndexOfMax (int * a, int n) {
    int max;
    if (n<1) { return 0;}
    max = 0;
    for (int i = 1; i<n; i++) {
        if ( a[i] > a[max] ) {
            max = i;
        }
    }
    return max;
}

void printArray(int * a, int n) {
    printf("%d", &a[0]);
    for (int i = 1; i<n; i++) {
        printf(", %d", &a[i]);
    }
}

int main (int argc, char** argv[]) {
    int n;
    printf("Enter number of elements in array.");
    scanf("%d",&n);
    int * a = generateArray(n);
    printArray(a, n);
}