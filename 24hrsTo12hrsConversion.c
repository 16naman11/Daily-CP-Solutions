#include <stdio.h>

int main() {
    int thh,thm,tfhh,tfhm;
    printf("enter time in 24hrs format(hh mm) : \n");
    scanf("%d %d",&tfhh,&tfhm);
    if(tfhh>12){
        thh=tfhh-12;
        printf("the time in 12hrs format is %d:%d pm",thh,tfhm);
    }
    else if(tfhh==0){
        printf("the time in 12hrs format is 12:%d am",tfhm);
    }
    else if(tfhh<13&&tfhh>0){
         printf("the time in 12hrs format is %d:%d am",tfhh,tfhm);
    }
    return 0;
}
