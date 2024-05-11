#include <stdio.h>

int main() {
    int a,ld;
    printf("enter an integer : ");
    scanf("%d", &a);
    ld=a%10;
    printf("the last digit is %d", ld);
    return 0;
}
