#include <stdio.h>

int main() {
   int a[100],se,i,n;
   printf("enter the no. of elements : \n");
   scanf("%d", &n);
   printf("enter the elements of the array : \n");
   for(i=0;i<n;i++){
       scanf("%d",&a[i]);
   }
   printf("enter the element to be searched : \n");
   scanf("%d",&se);
   for(i=0;i<n;i++){
       if(a[i]==se){
           printf("success\n");
       }
       else{
           printf("failure\n");
       }
   }
 

    return 0;
}
