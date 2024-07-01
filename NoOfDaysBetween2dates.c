#include <stdio.h>

int main() {
    int d,m,y,c,d1,m1,y1,c1,lyc1,lyc,tc,tc1,diff;
    
    
    /*d is day of 1st input
    m is month of 1st input
    y is year of 1st input
    c is count of days between input day and 1st january 
    the same for d1,m1,y1,c1
    lyc and lyc1 are the additional no. of days because of leap years
    tc and tc1 are total count of days between input and 1st jan 1900
    diff is the output*/
    
    
    printf("enter the first date in format ddmmyyyy :\n");
    scanf("%d%d%d",&d,&m,&y);
    printf("enter the second date in format ddmmyyyy :\n");
    scanf("%d%d%d",&d1,&m1,&y1);
    
    
    if(y%4==0){
        if(m==1)
        c=d;
        else if(m==2)
        c=d+31;
        else if(m==3)
        c=d+31+29;
        else if(m==4)
        c=d+31+29+31;
        else if(m==5)
        c=d+31+29+31+30;
        else if(m==6)
        c=d+31+29+31+30+31;
        else if(m==7)
        c=d+31+29+31+30+31+30;
        else if(m==8)
        c=d+31+29+31+30+31+30+31;
        else if(m==9)
        c=d+31+29+31+30+31+30+31+31;
        else if(m==10)
        c=d+31+29+31+30+31+30+31+31+30;
        else if(m==11)
        c=d+31+29+31+30+31+30+31+31+30+31;
        else
        c=d+31+29+31+30+31+30+31+31+30+31+30;
    }
    
    else if(y%4!=0){
        if(m==1)
        c=d;
        else if(m==2)
        c=d+31;
        else if(m==3)
        c=d+31+28;
        else if(m==4)
        c=d+31+28+31;
        else if(m==5)
        c=d+31+28+31+30;
        else if(m==6)
        c=d+31+28+31+30+31;
        else if(m==7)
        c=d+31+28+31+30+31+30;
        else if(m==8)
        c=d+31+28+31+30+31+30+31;
        else if(m==9)
        c=d+31+28+31+30+31+30+31+31;
        else if(m==10)
        c=d+31+28+31+30+31+30+31+31+30;
        else if(m==11)
        c=d+31+28+31+30+31+30+31+31+30+31;
        else
        c=d+31+28+31+30+31+30+31+31+30+31+30;
    }
    
    
    if(y1%4==0){
        if(m1==1)
        c1=d1;
        else if(m1==2)
        c1=d1+31;
        else if(m1==3)
        c1=d1+31+29;
        else if(m1==4)
        c1=d1+31+29+31;
        else if(m1==5)
        c1=d1+31+29+31+30;
        else if(m1==6)
        c1=d1+31+29+31+30+31;
        else if(m1==7)
        c1=d1+31+29+31+30+31+30;
        else if(m1==8)
        c1=d1+31+29+31+30+31+30+31;
        else if(m1==9)
        c1=d1+31+29+31+30+31+30+31+31;
        else if(m1==10)
        c1=d1+31+29+31+30+31+30+31+31+30;
        else if(m1==11)
        c1=d1+31+29+31+30+31+30+31+31+30+31;
        else
        c1=d1+31+29+31+30+31+30+31+31+30+31+30;
    }
    
    else if(y1%4!=0){
        if(m1==1)
        c1=d1;
        else if(m1==2)
        c1=d1+31;
        else if(m1==3)
        c1=d1+31+28;
        else if(m1==4)
        c1=d1+31+28+31;
        else if(m1==5)
        c1=d1+31+28+31+30;
        else if(m1==6)
        c1=d1+31+28+31+30+31;
        else if(m1==7)
        c1=d1+31+28+31+30+31+30;
        else if(m1==8)
        c1=d1+31+28+31+30+31+30+31;
        else if(m1==9)
        c1=d1+31+28+31+30+31+30+31+31;
        else if(m1==10)
        c1=d1+31+28+31+30+31+30+31+31+30;
        else if(m1==11)
        c1=d1+31+28+31+30+31+30+31+31+30+31;
        else
        c1=d1+31+28+31+30+31+30+31+31+30+31+30;
    }
    
    
    lyc=(y/4)-475;
    tc=c+(y-1900)*365+lyc;
    
    lyc1=(y1/4)-475;
    tc1=c1+(y1-1900)*365+lyc1;
    
    diff=tc1-tc;
    
    printf("the difference between these two dates is %d",diff);
    
    return 0;
}
