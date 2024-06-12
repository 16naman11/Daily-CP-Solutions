
//sum of series 1 +1/2+1/3.....1/n

#include <stdio.h>

int main() {
    float sum;
    int i,n;
    sum=0;
    
    printf("enter value of n : \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum=sum+((float)1/i);
    }
    printf("%f is the sum",sum);
    return 0;
}
