#include <stdio.h>

int main() {
    int num[10],i,greatest;
    
    
    for(i=0;i<=9;i++){
        printf("enter an integer : ");
        scanf("%d",&num[i]);
        
    }
    greatest=num[0];
    for(i=1;i<=9;i++){
        if(greatest<num[i])
            greatest=num[i];
    }
    printf("the greatest integer is %d", greatest);
    
    
    return 0;
}
