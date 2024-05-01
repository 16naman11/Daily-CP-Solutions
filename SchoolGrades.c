#include <stdio.h>
//check odd even 
int main() {
    int sum,phy,chem,bio,maths,eng;
    float p;
    printf("\nenter marks of 5 subjects:");
    scanf("%d%d%d%d%d",&phy,&chem,&bio,&maths,&eng);
    sum = phy + chem + bio + maths + eng;
    printf("\nthe sum is %d",sum);
    p = (sum/5);
    printf("\nthe percentage is %f",p);
    
    if(p<=100 && p>90){
        printf("\n grade a");
    }
   else if(p<=90 && p>80){
       printf("\n grade b");
   }
   else if (p<=80 && p>70){
       printf("\n grade c");
   }
   else if (p<=70 && p>60){
       printf("\n grade d");
   }
   
   else if (p<=60){
       printf("\n fail");
   }
   
    return 0;
}
