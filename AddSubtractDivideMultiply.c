#include <stdio.h>
int main() 
{
    int num1,num2, sum , sub , prd;
    float div;
    printf ("enter two integers: ");
    scanf ("%d%d", &num1, &num2);
    sum=num1+num2;
    printf("%d+%d=%d\n",num1,num2,sum);
    sub=num1-num2;
    printf("%d-%d=%d\n",num1,num2,sub);
    prd=num1*num2;
    printf("%d*%d=%d\n",num1,num2,prd) ;
    div=(float)num1/(float)num2;
    printf("%d/%d=%f\n",num1,num2,div);
    return 0;
}
