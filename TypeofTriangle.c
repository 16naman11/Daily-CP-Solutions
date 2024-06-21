#include <stdio.h>

int main() {
   int a , b , c ;
   printf ("enter 3 sides of a triangle : ");
   scanf("%d%d%d", &a , &b , &c);
   
   if (a==b==c){
       printf("triange is equilateral");
   }
   if((a!=b)&&(b!=c)&&(c!=a)){
       printf("triangle is scalene");
   }
    if(a==b||b==c||a==c){
        printf("triangle is isoceles");
    }
    return 0;
}
