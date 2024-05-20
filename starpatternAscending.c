#include <stdio.h>

int main() {
    int a,i;
    for(i=0;i<6;i++){
        for(a=1;a<=i;a++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
