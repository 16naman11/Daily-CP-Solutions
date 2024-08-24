#include <stdio.h>

int main()
{
   int a[100],mid,n,i,j,temp;
   printf("enter the no. of elements in the array : \n");
   scanf("%d",&n);
   printf("enter the elements of the array : \n");
   for(i=0;i<n;i++){
       scanf("%d",&a[i]);
   }
   if(n%2!=0){
       mid=(n-1)/2;
   }
   else{
       mid=n/2;
   }
   for(i = 0, j = n - 1; i < mid; i++, j--){
           temp=a[i];
           a[i]=a[j];
           a[j]=temp;
   }
   printf("the reversed array is:\n");
   for(i=0;i<n;i++){
       printf("%d ",a[i]);
   }
   
   
   return 0;
}
