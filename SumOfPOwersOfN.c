#include <stdio.h>

int main() {
    int n,i,sum;
    sum=0;
    printf("enter value of n :\n");
    scanf("%d",&n);
    
    for(i=1;i<=n;i++){
        sum=i*i+sum;
    }
    printf("sum of powers is %d",sum);
    
    return 0;
}
