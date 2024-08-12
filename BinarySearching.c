#include <stdio.h>

int main()
{
   int a[100],i,n,mid,high,low,key,pos;
   printf("enter the no. of elements : ");
   scanf("%d",&n);
   printf("enter the elements of the array : \n");
   for(i=0;i<n;i++){
       scanf("%d",&a[i]);
   }
    low=0;
    high=n-1;
    pos=-1;
   
   printf("enter the key : ");
   scanf("%d",&key);
   while(low<=high){
      
       mid=(low+high)/2;
       if(a[mid]==key){
           pos=mid+1;
           break;
       }
       else if(key>a[mid]){
           low=mid+1;
       }
       else if(key<a[mid]){
           high=mid-1;
       }
       
   }
   if(pos!=-1)
   printf("the key is at %d position.\n",pos);
   
   else
   printf("element not found.\n");
   
   
   return 0;
}
