#include <stdio.h>

int main()
{
   int a[100],n,na,i,ia,min,mina,j,ja,temp,tempa,b[100],c[200],k;
   printf("enter the no. of elements in array 1 : \n");
   scanf("%d",&n);
   printf("enter the no. of elements in array 2 : \n");
   scanf("%d",&na);
   printf("enter the elements of the array 1 : \n");
   for(i=0;i<n;i++){
       scanf("%d",&a[i]);
   }
   printf("enter the elements of the array 2 : \n");
   for(ia=0;ia<na;ia++){
       scanf("%d",&b[ia]);
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
   
   
   for(ia=0;ia<na-1;ia++){
       mina=ia;
       for(ja=ia+1;ja<na;ja++){
          if(b[ja]<b[mina]){
              mina=ja;
          }
       }
       if(mina!=ia){
           tempa=b[ia];
           b[ia]=b[mina];
           b[mina]=tempa;
       }
       
   }
   printf("the sorted array 1 in arranging order is : \n");
   for(i=0;i<n;i++){
       printf("%d \n",a[i]);
   }
   printf("the sorted array 2 in arranging order is : \n");
   for(ia=0;ia<na;ia++){
       printf("%d \n",b[ia]);
   }
   
   i=0;
   ia=0;
   k=0;
   
   while(i<n && ia<na){
       if(a[i]<=b[ia]){
           c[k]=a[i];
           i++;
       }
       else{
           c[k]=b[ia];
           ia++;
       }
       k++;
   }
   while(i<n){
       c[k]=a[i];
        i++;
        k++;
   }
   while(ia<na){
       c[k]=b[ia];
       ia++;
       k++;
   }
   printf("the merged array after sorting is :\n");
   for (k = 0; k < n + na; k++) {
        printf("%d \n", c[k]);
    }
   
   return 0;
}
