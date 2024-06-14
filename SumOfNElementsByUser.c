#include <stdio.h>

int main() {
    int a[100],n,i,sum=0,b;
    printf("enter no. of elements : \n");
    scanf("%d",&n);
    
    printf("enter value of element\n");
    for(i=0;i<n;i++){
        b=i+1;
        scanf("%d",&a[i]);
        printf("%d element is %d\n",b,a[i]);
        sum=sum+a[i];
    }
    printf("value of sum is %d\n",sum);
    
    return 0;
}
