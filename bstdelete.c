#include <stdio.h> 
#include <stdlib.h> 

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

nodeAddress BSTMin(nodeAddress x) {
    nodeAddress current = x;
    while (current->left) {
        current = current->left;
    }
    return current;
}

nodeAddress delete(nodeAddress root, int x) { 
   if (root==NULL) { return root;}

   if (x < root->val) {
       root->left = delete(root->left, x);
   }
   else if (x > root->val) {
       root->right = delete(root->right, x);
   }

   else {
       if (root->left == NULL) {
           nodeAddress temp = root->right;
           free(root);
           return temp;
       }
       else if (root->right == NULL) {
           nodeAddress temp = root->left;
           free(root);
           return temp;
        }
    nodeAddress temp = BSTMin(root->right);
    root->val = temp->val;
    root->right = delete(root->right, temp->val);
   }

   return root;
}

int main (int argc, char** argv) { 
    int n = inputSizeArray();
    int arr[n];
    fillArray(arr, n);
    selectionSort(arr, n);
    nodeAddress root = generateBSTFromArray(arr, 0, n-1);
    printBST(root);
    int x;
    printf("Enter value to delete: ");
    scanf("%d", &x);
    root = delete(root, x);
    printBST(root);
}
