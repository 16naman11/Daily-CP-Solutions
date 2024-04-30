#include <stdio.h>

int main() {
   //celcius to farheneit conversion
   
   int c , f , c1 , f1;
   printf("enter temp in celcius:");
   scanf("%d", &c1);
   f = (c1*9/5)+32;
   printf("temp in degree farheneit : %d",f );
   
   printf("\nenter temp in farheneit: ");
   scanf("%d", &f1);
   c=(f1-32)*5/9;
   printf("temp in degree celcius : %d",c);
    return 0;
}



