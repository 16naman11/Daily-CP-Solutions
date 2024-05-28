#include <stdio.h>

int main() {
    int h,t,u,a=347;
    h=a/100;
    t=(a%100)/10;
    u=a%10;
    
    printf("the value at hundreds place is %d\n",h);
    printf("the value at tens place is %d\n",t);
    printf("the value at units place is %d\n",u);

    return 0;
}
