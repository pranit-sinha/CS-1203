#include <stdio.h> 
#include <stdlib.h> 
 
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

int findIndexOfMax(int *a, int n) {
    int imax;
    if (n<2) {
        return -1;}
    imax = 2;
    for (int i = 5; i<n; i=i+3) {
        if (a[i] > a[imax]) {
            imax = i;
        }
    }
    return imax;
}

int* sortEveryThirdElement(int *a, int n) {
    int end;
    if (n%3==0) {
        end = n;
    }
    else if (n%3==1) {
        end = n-1;
    }
    else {
        end = n-2;
    }
    int imax;
    for (int i = end; i >= 2; i=i-3) {
        imax = findIndexOfMax(a, i);
	    int temp = a[imax];
        a[imax] = a[i-1];
        a[i-1] = temp;
    }
    return a;
}

int normalFindIndexOfMax(int *a, int n) {
	int imax; // this will contain the address of the largest element encountered.
	int i;

	// error case if there are no elements in the list
	if(n<1) {return -1;}

	imax = 0; // I am assuming that a[0] is the max element
	for(i=1; i<n; i++) {
		if( a[i] > a[imax] ) {
			imax = i;
		}
	}

	return imax;
}

void selectionSort(int *a, int n) {
	int i, imax, t;

	for(i=n; i>1; i=i-1) {
		imax = normalFindIndexOfMax(a, i);
		t = a[imax]; a[imax] = a[i-1]; a[i-1] = t;
	}
}
void kSmallestAmongUntouched(int *a, int k, int n) {
    selectionSort(a, n);
    for (int i = 0; i < k; i++){
        if ((i+1)%3==0) {
            k=k+1;
            continue;
        }
        printf("%d ", a[i]);
    }
}
    

int main (int argc, char** argv) { 
    int n = inputSizeArray();
    int a[n];
    fillArray(a, n);
    printArray(a, n);
    int* sarr;
    sarr = sortEveryThirdElement(a, n);
    printArray(a, n);
    int k;
    printf("Enter k: ");
    scanf("%d", &k);
    kSmallestAmongUntouched(sarr, k, n);
}
