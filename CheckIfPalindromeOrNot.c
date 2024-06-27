#include <stdio.h>

int main() {
    int tth,th,h,t,u,a;
    printf("enter the number : \n");
    scanf("%d",&a);
    tth=(a/10000)%10;
    th=(a/1000)%10;
    h=(a/100)%10;
    t=(a%100)/10;
    u=a%10;
    
    if(a>0&&a<10){
        printf("no result");
    }
    else if(a>9 && a<100){
        if(u==t){
            printf("the number is a palindrome \n");
        }
        else{
            printf("the number is not a palindrome \n");
        }
    }
    else if(a>99 && a<1000){
        if(u==h){
            printf("the number is a palindrome \n");
        }
        else{
            printf("the number is not a palindrome \n");
        }
        
    }
    else if(a>999 && a<10000){
        if(u==th&&h==t){
            printf("the number is a palindrome \n");
        }
        else{
            printf("the number is not a palindrome \n");
        }
    }   
    else if(a>9999 && a<100000){
        if(u==tth&&th==t){
            printf("the number is a palindrome \n");
        }
        else{
            printf("the number is not a palindrome \n");
        }
    }
    return 0;
}
