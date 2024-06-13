//sum of series 1 + 3 + 5 +.......+n

#include <stdio.h>

int main() {
    float sum;
    int i,n;
    sum=0;
    
    printf("enter value of n : \n");
    scanf("%d",&n);
    for(i=1;i<=n;i=i+2){
        sum=sum+i;
        i;
    }
    printf("%f is the sum",sum);
    return 0;
}
