#include <stdio.h>

int main()
{
   int a[100],n,i,min,j,temp;
   printf("enter the no. of elements in the array : \n");
   scanf("%d",&n);
   printf("enter the elements of the array : \n");
   for(i=0;i<n;i++){
       scanf("%d",&a[i]);
   }
   
   for(i=0;i<n-1;i++){
       min=i;
       for(j=i+1;j<n;j++){
          if(a[j]<a[min]){
              min=j;
          }
       }
       if(min!=i){
           temp=a[i];
           a[i]=a[min];
           a[min]=temp;
       }
       
   }
   printf("the sorted array in arranging order is : \n");
   for(i=0;i<n;i++){
       printf("%d ",a[i]);
   }
   return 0;
}
