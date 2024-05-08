#include <stdio.h>

int main() {
   int books[10],i,sum=0,total;
   float discount;
   for(i=0;i<10;i++){
       printf("enter the mrp of book : ");
       scanf("%d", &books[i]);
       sum=sum+books[i];
   }
   
   printf("before disc = %d \n", sum);
   discount = (sum/100)*20;
   total = sum - discount;
   printf("amount after discount : %d", total);
   

    return 0;
}
