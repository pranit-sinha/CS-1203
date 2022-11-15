#include <stdio.h> 
#include <stdlib.h> 
#include "headers/Array.h"

struct node {
    int val;
    struct node * left;
    struct node * right;
};

typedef struct node * nodeAddress;

nodeAddress generateBSTFromArray(int * arr, int a, int b, nodeAddress root) {
    if(a>b) { return NULL;}
    int c = (a+b)/2;
    if (root==NULL) {
        root->val = arr[c];
    }
    root->left = generateBSTFromArray(arr, a, c-1, root->left);
    root->right = generateBSTFromArray(arr, c+1, b, root->right);
    return root;
}

void printBST(nodeAddress root, int height) {
    if (root == NULL) {return;}
    printf("%d\n", root->val);
    printBST(root->left, height + 1);
    printBST(root->right, height + 1);
}
 
int main (int argc, char** argv) { 
    int n = inputSizeArray();
    int arr[n];
    fillArray(arr, n);
    selectionSort(arr, n);
    nodeAddress root = NULL;
    root = generateBSTFromArray(arr, 0, n-1, root);
    printBST(root, 0);
}



