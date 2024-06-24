#include <stdio.h>

int main() {
    int yr,i;
    printf("enter year : \n");
    scanf ("%d",&yr);
    i=1;
    while(i<=yr){
        if(i%4==0){
            printf(" %d is a leap year \n" , i);
        }
        else{
            printf(" %d is not a leap year \n", i);
        }
        i++;
    }
    return 0;
}
