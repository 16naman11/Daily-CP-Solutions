#include <stdio.h>

int main() {
    int a,i;
    for(i=0;i<5;i++){
        for(a=1; a<=i ;a++){
            printf("%d ",a);

        }
        printf("\n");
    }
    return 0;
}
