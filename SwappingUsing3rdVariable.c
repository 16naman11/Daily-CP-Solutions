#include<stdio.h>
int main() 
{
    int a,b,c;
    printf("enter 2 integers: ");
    scanf("%d%d", &a , &b);
    printf ("before swapping a=%d , b=%d", a,b);
    
    c = a ;
    a = b ;
    b = c ;
    
    printf("after swapping a=%d , b =%d", a,b);
    return 0;
}
