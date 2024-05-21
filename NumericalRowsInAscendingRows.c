#include <stdio.h>

int main() {
    int a,i,m;
    m=1;
    for(i=0;i<5;i++){
        for(a=1; a<=i ;a++){
            printf("%d ", m);
             m++;
        }
        printf("\n");
    }
    return 0;
}
