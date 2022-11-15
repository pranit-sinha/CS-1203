#include <stdio.h> 
#include <stdlib.h> 
#include "headers/Array.h"

struct node {
    int val;
    struct node * left;
    struct node * right;
};

typedef struct node * nodeAddress;

nodeAddress generateBSTFromArray(int * arr, int a, int b)  {
    if(a>b) { return NULL;}
    int c = (a+b)/2;
    nodeAddress root = malloc(sizeof(struct node));
    root->val = arr[c];
    root->left = generateBSTFromArray(arr, a, c-1);
    root->right = generateBSTFromArray(arr, c+1, b);
    return root;
}

void printBST(nodeAddress root) {
    if (root == NULL) {return;}
    printBST(root->left);
    printf("%d\n", root->val);
    printBST(root->right);
}
 
int main (int argc, char** argv) { 
    int n = inputSizeArray();
    int arr[n];
    fillArray(arr, n);
    selectionSort(arr, n);
    nodeAddress root = generateBSTFromArray(arr, 0, n-1);
    printBST(root);
}



