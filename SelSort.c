#include <stdio.h> 
#include <stdlib.h> 
 
int findIndexOfMax(int *a, int n) {
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
		imax = findIndexOfMax(a, i);
		t = a[imax]; a[imax] = a[i-1]; a[i-1] = t;
	}
}
