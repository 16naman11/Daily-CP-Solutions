#include <stdio.h>

int main() {
    int n,m,odd,even; 
    printf("enter a nmber :\n");
    scanf("%d",&n);
    m=n-1;
    if(n/2==m/2){
        printf("no. is odd");
    }
    else{
        printf("no. is even");
    }
    return 0;
}
