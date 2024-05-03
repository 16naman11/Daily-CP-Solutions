#include <stdio.h>

int main() {
    int a;
    printf("enter value of a : ");
    scanf ("%d" , &a);
   
    if ( a%7==0){
        printf("the integer is a multiple of 7");
       
    }
else{
    printf("the integer is not a multiple of 7");
}
    return 0;
}
