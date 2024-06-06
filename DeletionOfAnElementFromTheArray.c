#include<stdio.h>
int main() {
    int a[10],j,i,count=0,index,n,size;
    printf("enter  the no. of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        count++;
    }
    printf("enter index:");
    scanf("%d",&index);
    for(j=index;j<count;j++)
        {
            a[j]=a[j+1];
            count--;
        }
    printf("enter value");
    scanf("%d",&a[index]);
   
    for(i=0;i<count+1;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}
