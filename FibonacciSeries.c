#include <stdio.h>

int main() {
    int a=0,b=1,c;
   
    while(c<150){
        
        printf("%d \n", c);
        a=b;
        b=c;
        c=a+b;
        
        
    }
    
    return 0;
}
