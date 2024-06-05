#include <stdio.h>

int main() {
    int i,a[10],j,k,count=0,size=10,e,index;
   
    printf("enter elements of array : \n");
    for(i=0;i<5;i++){
        scanf("%d",&a[i]);
        count++;
    }
    e=size-count; 
    if(size==count){
        printf("the array is full\n");
    }
    else{
        printf("array has %d spaces left \n",e);
        
        printf("enter the index no. where you want to add a new no.\n");
        scanf("%d",&index);
        for(j=i;j>=index;j--){
            a[j]=a[j-1];
         }
         printf("enete the element to be inserted : \n");
         scanf("%d", &a[index]);
    }
    for(i=0;i<count+1;i++){
        printf("%d ",a[i]);
    }
   
    return 0;
}
