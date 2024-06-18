#include <stdio.h>

int main() {
    int n,i,j,count,f;
    printf("enter a number : \n");
    scanf("%d",&n);
    f=n;
    for(i=2;i<n;i++){
        if(n%i==0){
            count=0;
            for(j=1;j<=i;j++){
                if(i%j==0)
                    count=count+1;
            }    
            if(count==2){
                printf("%d is a prime factor of %d\n",i,n);
                f=f/i;
            }
        }
    }
    return 0;
}
