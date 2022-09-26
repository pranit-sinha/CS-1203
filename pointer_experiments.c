#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv) {
    int x = 3;
    int *y;
    y = &x;
    *y = *y + 1;

    printf("%d\n", x);

    int *a;
    a = malloc(1000*sizeof(int)); // or (int*) malloc... 
    printf("%d",*(a+2)); // since a is an integer, (a+1) gives you the next integer (4 bytes after where a is) rather than the next byte. (a+0) ... (a+999) is the full range of addresses allocated to you.a[0] ... a[999] would syntactically mean the same thing.
    char *b;
    b = (char*) a;
    printf("%d",*(b+1));
}
