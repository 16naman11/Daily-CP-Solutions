#include <stdio.h>

int main() {
    // program for marksheet in c 
    
    int maths,chem,ed,eng,beee,roll,total;
    char name;
    float per;
    
    printf("enter your name :  ");
    scanf("%s",&name);
    printf("enter your roll no. : \n");
    scanf("%d",&roll);
    printf("enter marks in maths : \n");   
    scanf("%d",&maths);
    printf("enter marks in chem : \n");
    scanf("%d",&chem);
    printf("enter marks in ed : \n");
    scanf("%d",&ed);
    printf("enter marks in eng : \n");
    scanf("%d",&eng);
    printf("enter marks in beee : \n");
    scanf("%d",&beee);
    
    total=maths+chem+ed+eng+beee;
    per= total/5;
    
    if(per>=75){
        printf(" grade : distinction");
    }
    else if(per>=60&&per<75){
        printf(" grade : second division");
    }
    else if(per>=36&&per<60){
        printf("grade : pass");
    }
    else{
        printf("grade : fail");
    }
    printf("\n\n\n");
    printf("---------------------------------------------------\n");
    printf("   SUBJECT             max/min           obtained  \n");
    printf("---------------------------------------------------\n");
    printf("    chem                100/36            %d\n ", chem);
    printf("    math                100/36            %d\n ",maths);
    printf("     ed                100/36             %d\n ", ed);
    printf("    beee                100/36            %d\n ", beee);
    printf("    eng                100/36            %d\n ", eng);
    printf("---------------------------------------------------\n");
    printf("                                      TOTAL : %d\n",total);
    printf("percentage : %f \n", per);
    printf("---------------------------------------------------\n");
    


    
    return 0;
}
