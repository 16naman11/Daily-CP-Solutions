#include <stdio.h>

int main() {
    int n,count=0,i;
    printf("enter a number : \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(n%i==0){
            count=count+1;
        }
    }
    if(count==2){
        printf("its a prime no.\n");
    }
    else{
        printf("its not a prime no.\n");
    }
    return 0;
}
     