#include <stdio.h>
//check odd even 
int main() {
    int a,b,c;
    printf("enter values of a,b,c : ");
    scanf("%d%d%d",&a,&b,&c);
    
    if(a>b && b>c){
        printf("a is the largest");
    }
    else if (b>a && a>c){
        printf("b is the largest");
        
    } 
    
    else{
        printf("c is the largest");
    }
    
    return 0;
}