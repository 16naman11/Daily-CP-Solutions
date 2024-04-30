#include<stdio.h>

int main()
{
    int a,p,t,i;
    float r;
    printf ("enter p\n : ");
    scanf ("%d", &p);
    printf ("enter r\n : ");
    scanf ( "%f", &r);
    printf ("enter t\n : ");
    scanf ( "%d", &t);
    
    a=p*(1+r*t);
    printf ("a=%d\n",a);
    
    return 0 ;
}




