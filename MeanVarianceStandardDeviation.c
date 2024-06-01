#include <stdio.h>
#include <math.h>

int main() {
      float arr[100],n,mean,sum_var,var,std_dev,sum;
      int i;
      printf("enter the size of array less than 100: \n");
      scanf("%f",&n);
      sum=0.0;
      printf("enter elements of array : \n");
      for(i=0;i<n;i++){
          scanf("%f",&arr[i]);
          sum=sum+arr[i];
      }
      mean=sum/n;
      printf("the mean is %f\n",mean);
      sum_var=0;
      
      for(i=0;i<n;i++){
          sum_var=sum_var+pow((arr[i]-mean),2);
      }
      
      var=sum_var/n;
      
      printf("the varriance is %f \n",var);
     
     std_dev=sqrt(var);
     
     printf("the value of std deviation is %f\n", std_dev);
     
      
    return 0;
}
