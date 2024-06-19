#include <stdio.h>

int main() {
    int dec,i,tth,th,h,t,u,a,sum;
    printf("enter the number : \n");
    scanf("%d",&a);
    tth=(a/10000)%10;
    th=(a/1000)%10;
    h=(a/100)%10;
    t=(a%100)/10;
    u=a%10;

    if(a>0&&a<10){
        dec=u;
        printf("%d is the binary conversion of %d to decimal",dec,a);
    }
    
    else if(a>9 && a<100){
         dec=u*2+t*2;
        printf("%d is the binary conversion of %d to decimal",dec,a);
    }
    else if(a>99 && a<1000){
         dec=u+t*2+h*2*2;
        printf("%d is the binary conversion of %d to decimal",dec,a);
        
    }
    else if(a>999 && a<10000){
       dec=u+t*2+h*2*2+th*2*2*2;
        printf("%d is the binary conversion of %d to decimal",dec,a);
    }   
    else if(a>9999 && a<100000){
         dec=u+t*2+h*2*2+th*2*2*2+tth*2*2*2*2;
        printf("%d is the binary conversion of %d to decimal",dec,a);
    }

    
    return 0;
}
