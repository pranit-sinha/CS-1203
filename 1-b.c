#include <stdio.h> 
#include <stdlib.h> 
 
void advancedFizzBuzz(int *a, int m, int *b, int nb, int *f, int nf) {
    int flag=0,bflag=0,fflag=0;
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<nb; j++) {
            if(a[i]%b[j]==0) {
                flag = flag+1;
                bflag = 1;
            }
        }
        for (int k = 0; k<nf; k++) {
            if(a[i]%f[k]==0) {
                flag = flag+1;
                fflag=1;
            }
        }
        if(flag==2) {                       // we use three flags to indicate which of the three messages we should print
            printf("fizzbuzz\n");
        }
        else if(flag==1 && fflag==1) {
            printf("fizz\n");
        }
        else if(flag==1 && bflag==1) {
            printf("buzz\n");
        }
    }
}

int main (int argc, char** argv) { 
    int m;
    printf("Enter number of elements in input array a. ");
    scanf("%d",&m);
    int a[m];
    for (int i = 0; i < m; i++) {
        printf("Enter element in position %d: ", i);
        scanf("%d", &a[i]);
    }
    int nb;
    printf("Enter number of elements in input array b. ");
    scanf("%d",&nb);
    int b[nb];
    for (int i = 0; i < nb; i++) {
        printf("Enter element in position %d: ", i);
        scanf("%d", &b[i]);
    }
    int nf;
    printf("Enter number of elements in input array f. ");
    scanf("%d",&nf);
    int f[nf];
    for (int i = 0; i < nf; i++) {
        printf("Enter element in position %d: ", i);
        scanf("%d", &f[i]);
    }
    advancedFizzBuzz(a, m, b, nb, f, nf);
}

