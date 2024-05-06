#include <stdio.h>

int main() {
    int i,a,n;
    i=1;
    printf("enter value of n : \n");
    scanf("%d",&n);
    while (i<=n){
        if(i%2==0){
            printf("this number is even : %d \n",i);
        }
        else{
            printf("this numbers is odd : %d \n" , i);
        }
        i++;
    }
    
    return 0;
}
