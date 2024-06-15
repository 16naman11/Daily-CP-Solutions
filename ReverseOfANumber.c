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
        printf("no reversal\n");
    }
    else if(a>9 && a<100){
        a = t + (u*10) ;
        printf("the revered number is %d",a); 
    }
    else if(a>99 && a<1000){
        a = h + (t*10) + (u*100) ;
        printf("the revered number is %d",a); 
    }
    else if(a>999 && a<10000){
        a = th + (h*10) + (t*100) + (u*1000) ;
        printf("the revered number is %d",a); 
    }
    else if(a>9999 && a<100000){
        a = tth + (th*10) + (h*100) + (t*1000) + (u*10000) ;
        printf("the revered number is %d",a); 
    }
    return 0;
}
