#include <stdio.h>

int main() {
    int d,m,y;
    printf("enter date in format ddmmyyyy :\n");
    scanf("%d%d%d",&d,&m,&y);
    
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        if(d==31){
            if(m==12){
                y=y+1;
                printf("the following day is 1 1 %d",y);
            }
            else{
                 m=m+1;
            printf( "the following day is 1 %d %d",m,y);
            }
        }
            
        else {
            d=d+1;
            printf("the following day is %d %d %d",d,m,y);
        }
        
    }
    else if(m==4||m==6||m==9||m==11){
        if(d==30){
            m=m+1;
            printf("the following day is 1 %d %d",m,y);
        }
        else{
            d=d+1;
            printf("the following day is %d %d %d",d,m,y);
            
        }
        
    }
    else if(m==2){
        if(y%4==0){
            if(d==29){
                m=3;
                printf("the following day is 1 2 %d",y);
            }
            else {
                d=d+1;
                printf("the following day is %d 2 %d",d,y);
            }
        }
        else{
            if(d==28){
                m=3;
                printf("the following day is 1 2 %d",y);
            }
            else {
                d=d+1;
                printf("the following day is %d 2 %d",d,y);
            }
        }
    }
    
   
    return 0;
}
