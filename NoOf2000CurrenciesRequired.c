#include <stdio.h>

int main() {
    int amt,notes,rem;
    printf("enter the amount : \n");
    scanf("%d", &amt);
    rem=amt%2000;
    notes=(amt-rem)/2000;
    
    printf("the no. of notes req are %d",notes);
    return 0;
}
