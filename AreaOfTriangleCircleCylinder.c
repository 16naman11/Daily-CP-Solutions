#include<stdio.h>

int main() 
{
    int r , h , b;
    float a_cir,a_cyl,a_tri;
    printf ("enter r\n : ");
    scanf ("%d",&r);
    printf ("enter b\n : ");
    scanf ("%d", &b);
    printf ("enter h\n ; ");
    scanf("%d", &h);

a_cir= 3.14*r*r;
a_tri=0.5*b*h;
a_cyl=2*3.14*r*(r+h);

printf ("a_cir=%f\n",a_cir);
printf("a_tri=%f\n",a_tri);
printf("a_cyl=%f\n",a_cyl);
    return 0 ;
}
    
