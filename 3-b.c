#include <stdio.h> 
#include <stdlib.h> 
 
struct node {
    int val;
    struct node * left;
    struct node * right;
};

typedef struct node * NodeAddress;

/* AUXILIARY FUNCTIONS BEGIN HERE
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
		t = a[imax]; a[imax] = a[i-1]; a[i-1] = t;
	}
}

NodeAddress arrayToReverseBST(int *a, int init, int fin) {
    if(init>fin) { return NULL;}
    int mid = (init+fin)/2;
    NodeAddress root = malloc(sizeof(struct node));
    root->val = a[mid];
    root->left = arrayToReverseBST(a, mid+1, fin);
    root->right = arrayToReverseBST(a, init, mid-1);
    return root;
    return root;
}

void prefixPrint(NodeAddress root) {
    if (root == NULL) {return;}
    printf("%d\n", root->val);
    prefixPrint(root->left);
    prefixPrint(root->right);
}

/*  +
    +
    +
    +
    AUXILIARY FUNCTIONS END HERE
*/

int reverseBSTMax(NodeAddress x) {
    NodeAddress current = x;
    while (current->left) {
        current = current->left;
    }
    return current->val;
}

int reverseBSTMin(NodeAddress x) {
    NodeAddress current = x;
    while (current->right) {
        current = current->right;
    }
    return current->val;
}

void successorReverseBST(NodeAddress root, int k) {
    if (root==NULL) {               
        return;
    }
    
    NodeAddress successor;

    if (root->val==k) {
        if (root->left) {
             printf("The successor is %d\n", reverseBSTMin(root->left));
        }
        return;
    }
    
    if (root->val > k) {
        successor = root;
        successorReverseBST(root->right, k);        
    }
    else {
        successorReverseBST(root->left, k);
    }
    if (successor==NULL) { 
        printf("Hamburger");
    }
    else {
        printf("The successor is %d\n", successor->val);
    }
}

int main (int argc, char** argv) { 
    int n = inputSizeArray();
    int a[n];
    fillArray(a, n);
    selectionSort(a, n);
    NodeAddress root = arrayToReverseBST(a, 0, n-1);
    prefixPrint(root);
    int k;
    printf("Enter element to be found successor of: ");
    scanf("%d",&k);
    successorReverseBST(root, k);
}

