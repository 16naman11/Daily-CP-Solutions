#include <stdio.h>

int main() {
    int i,cube,n , square ;
    
    i=1;
    
    printf("enter value of n : \n");
    scanf("%d",&n);
    while(i<=n){
        printf ("value of cube is : %d \n", i*i*i);
        printf("value of square is : %d \n" , i*i);
        
        i=i+1 ;
        
    }
    return 0;
}
