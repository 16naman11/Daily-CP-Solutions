#include <stdio.h>

int main() {
    int n,i,sum,avg;
    sum=0;
    printf("value of n : \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum=sum+i;
    }
    printf("sum is %d\n",sum);
    avg=sum/n;
    printf("average is %d\n",avg);
    
    return 0;
}
