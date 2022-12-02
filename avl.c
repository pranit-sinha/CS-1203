#include <stdio.h> 
#include <stdlib.h> 
#include "headers/Array.h"
#include "headers/Sort.h"

struct Node {
    int val;
    struct Node * left;
    struct Node * right;
    int height;
};

typedef struct Node * NodeAddress; 
 
int height (NodeAddress n) {
    if (n==NULL) {
        return 0;
    }
    return n->height;
}

NodeAddress rightRotate (NodeAddress x) {
    NodeAddress y = x->left;
    NodeAddress z = y->right;
    y->right = x;
    x->left = z;
    x->height= x->left->height > (x->right->height)+1 ? x->left->height : (x->right->height)+1;
    y->height= y->left->height > (y->right->height)+1 ? y->left->height : (y->right->height)+1;
    return y;
}

NodeAddress leftRotate(NodeAddress x) {
    NodeAddress y = x->right;
    NodeAddress z = y->left;
    y->left = x;
    x->right = z;
    x->height= x->left->height > (x->right->height)+1 ? x->left->height : (x->right->height)+1;
    y->height= y->left->height > (y->right->height)+1 ? y->left->height : (y->right->height)+1;
}

NodeAddress generateAVLFromArray(int * arr, int a, int b)  {
    if(a>b) { return NULL;}
    int c = (a+b)/2;
    NodeAddress root = malloc(sizeof(struct Node));
    root->val = arr[c];
    root->left = generateAVLFromArray(arr, a, c-1);
    root->right = generateAVLFromArray(arr, c+1, b);
    return root;
}

void printAVL(NodeAddress root) {
    if (root == NULL) {return;}
    printAVL(root->left);
    printf("%d\n", root->val);
    printAVL(root->right);
}

int main (int argc, char** argv) { 
    int n = inputSizeArray();
    int a[n];
    fillArray(a, n);
    selectionSort(a, n);
    NodeAddress root = generateAVLFromArray(a, 0, n-1);
    printAVL(root);
}

