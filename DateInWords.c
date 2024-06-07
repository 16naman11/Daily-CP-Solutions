#include <stdio.h>

int main() {
    int d,m,y;
    printf("enter a date : \n");
    scanf("%d %d %d",&d,&m,&y);
    if(m==1)
    printf("the date is January %d, %d",d,y);
    else if(m==2)
    printf("the date is February %d, %d",d,y);
    else if(m==3)
    printf("the date is March %d, %d",d,y);
    else if(m==4)
    printf("the date is April %d, %d",d,y);
    else if(m==5)
    printf("the date is May %d, %d",d,y);
    else if(m==6)
    printf("the date is June %d, %d",d,y);
    else if(m==7)
    printf("the date is July %d, %d",d,y);
    else if(m==8)
    printf("the date is August %d, %d",d,y);
    else if(m==9)
    printf("the date is September %d, %d",d,y);
    else if(m==10)
    printf("the date is October %d, %d",d,y);
    else if(m==11)
    printf("the date is November %d, %d",d,y);
    else
    printf("the date is December %d, %d",d,y);
    return 0;
}
