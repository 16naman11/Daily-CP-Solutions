#include <stdio.h>

int main() {
    int a,b,sum;
    printf("enter a 3 digit integer : \n");
    scanf("%d", &a);
    sum=0;
    while(a>0){
        b=a%10;	
        sum=sum+b;
        a=a/10;
    }
    printf("the sum is %d",sum);
    return 0;
}
