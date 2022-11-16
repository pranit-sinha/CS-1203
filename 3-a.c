#include <stdio.h> 
#include <stdlib.h> 

struct node {
    int val;
    struct node * left;
    struct node * right;
};

typedef struct node * NodeAddress;

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
	int i;
	if(n<1) {return -1;}
	imax = 0; 
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
		t = a[imax];
        a[imax] = a[i-1];
        a[i-1] = t;
	}
}

NodeAddress arrayToReverseBSTRecursive(int *a, int init, int fin) {
    if(init>fin) { return NULL;}
    int mid = (init+fin)/2;
    NodeAddress root = malloc(sizeof(struct node));
    root->val = a[mid];
    root->left = arrayToReverseBSTRecursive(a, mid+1, fin);
    root->right = arrayToReverseBSTRecursive(a, init, mid-1);
    return root;
}

NodeAddress arrayToReverseBST (int* a, int n) {
    NodeAddress root = arrayToReverseBSTRecursive(a, 0, n-1);
    return root;
}

void prefixPrint(NodeAddress root) {
    if (root == NULL) {return;}
    printf("%d\n", root->val);
    prefixPrint(root->left);
    prefixPrint(root->right);
}
 
int main (int argc, char** argv) { 
    int n = inputSizeArray();
    int a[n];
    fillArray(a, n);
    selectionSort(a, n);
    NodeAddress root = arrayToReverseBST(a, n);
    prefixPrint(root);
}

