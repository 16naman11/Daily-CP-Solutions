#include <stdio.h>

int main() {
    int a,b;
    printf("enter 2 integers : \n");
    scanf("%d %d",&a,&b);
    
    if(b%a==0)
    printf("%d is a multiple of %d",b,a);
    
    else
    printf("%d is not a multiple of %d",b,a);
    
    return 0;
}
