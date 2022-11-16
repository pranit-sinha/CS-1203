#include <stdio.h> 
#include <stdlib.h> 
 
void basicFizzBuzz(int x) {
    if (x%33==0 || x%55==0 || x%39==0 || x%65==0) {
        printf("fizzbuzz\n");
    }
    else if (x%3==0 || x%5==0) {
        printf("fizz\n");
    }
    else if (x%11==0 || x%13==0) {
        printf("buzz\n");
    }
    else {
        printf("%d\n", x);
    }
}

int main (int argc, char** argv) { 
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);
    basicFizzBuzz(x);
}

