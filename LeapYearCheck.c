#include <stdio.h>

int main() {
   //leap year check
   
   int year;
   printf ("enter the year : ");
   scanf("%d", &year);
   if(year%4==0){
       printf("\ngiven year is a leap year");
   }
   else{
       printf("\ngiven year is not a leap year");
   }
    return 0;
}


