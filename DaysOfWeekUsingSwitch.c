#include <stdio.h>

int main() {
   int a , b ,c , choice ;
   printf("\n enter 1 for monday");
   printf("\n enter 2 for tuesday");
   printf("\n enter 3 for wednesday");
   printf("\n enter 4 for thursday");
   printf("\n enter 5 for friday");
   printf("\n enter 6 for saturday");
   printf("\n enter 7 for sunday\n");
   scanf("%d", &choice);
   switch(choice)
   {
       case 1:
       printf("monday");
       break;
       
       case 2:
       printf("tuesday");
       break;
       
       case 3:
       printf("wednesday");
       break;
       
       case 4:
       printf("thursday");
       break;
       
       case 5:
       printf("friday");
       break;
       
       case 6:
       printf("saturday");
       break;
       
       case 7:
       printf("sunday");
       break;
       
       default:
       printf("you have entered the wromg key \n press any other key to continue \n");
   }

    return 0;
}
