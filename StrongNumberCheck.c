#include <stdio.h>

int main() {
    int fact_u,fact_t,fact_h,fact_th,fact_tth,i,tth,th,h,t,u,a,sum;
    printf("enter the number : \n");
    scanf("%d",&a);
    tth=(a/10000)%10;
    th=(a/1000)%10;
    h=(a/100)%10;
    t=(a%100)/10;
    u=a%10;
    
    
    fact_u=1;
    for(i=1;i<=u;i++){
        fact_u=fact_u*i;
    }
    
    fact_t=1;
    for(i=1;i<=t;i++){
        fact_t=fact_t*i;
    }
    
    fact_h=1;
    for(i=1;i<=h;i++){
        fact_h=fact_h*i;
    }
    
    fact_th=1;
    for(i=1;i<=th;i++){
        fact_th=fact_th*i;
    }
    
    fact_tth=1;
    for(i=1;i<=tth;i++){
        fact_tth=fact_tth*i;
    }

    
    if(a>0&&a<10){
        sum=fact_u;
        if(sum==a){
            printf("%d is a strong number\n",a);
        }
        else{
            printf("%d is not a strong number\n",a);
        }
    }
    
    else if(a>9 && a<100){
         sum=fact_u+fact_t;
        if(sum==a){
            printf("%d is a strong number\n",a);
        }
        else{
            printf("%d is not a strong number\n",a);
        }
    }
    else if(a>99 && a<1000){
         sum=fact_u+fact_t+fact_h;
        if(sum==a){
            printf("%d is a strong number\n",a);
        }
        else{
            printf("%d is not a strong number\n",a);
        }
        
    }
    else if(a>999 && a<10000){
        sum=fact_u+fact_t+fact_h+fact_th;
        if(sum==a){
            printf("%d is a strong number\n",a);
        }
        else{
            printf("%d is not a strong number\n",a);
        }
    }   
    else if(a>9999 && a<100000){
         sum=fact_u+fact_t+fact_h+fact_th+fact_tth;
        if(sum==a){
            printf("%d is a strong number\n",a);
        }
        else{
            printf("%d is not a strong number\n",a);
        }
    }

    
    return 0;
}
