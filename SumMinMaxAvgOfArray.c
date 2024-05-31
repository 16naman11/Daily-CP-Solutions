#include <stdio.h>

int main() {
      int arr[100],i,n,min,sum,avg,max;
      printf("enter the size of array less than 100: \n");
      scanf("%d",&n);
      sum=0;
      printf("enter elements of array : \n");
      for(i=0;i<n;i++){
          scanf("%d",&arr[i]);
          sum=sum+arr[i];
      }
      printf("the sum is %d\n", sum);
      avg=sum/n;
      printf("the average is %d\n",avg);
      min=arr[0];
      for(i=1;i<n;i++){
          if(min>arr[i]){
              min=arr[i];
          }
      }
      printf("the minimum element of the array is %d\n", min);
      
       max=arr[0];
      for(i=1;i<n;i++){
          if(max<arr[i]){
              max=arr[i];
          }
      }
      printf("the maximum element of the array is %d\n", max);
      
      
    return 0;
}
