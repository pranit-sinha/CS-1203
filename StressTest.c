#include <stdio.h> 
#include <stdlib.h> 
 
int main (int argc, char** argv) { 
    float inc;
    printf("Enter increment amount: ");
	scanf("%f",&inc);
    float n = 10*inc;
    int count = 1;

    for (float i = 0; i<n; i = i+inc) {
        printf("Loop iteration #%d\n", count);
        count++;
    }

    return 0; 
}

