#include <stdio.h>

int main() {
    int a,b;
    float per;
    printf("enter values of a and b : \n");
    scanf("%d %d", &a,&b);
    per = (float)a/b*100;
    printf("the percentage of one integer wrt the other integer is : %f", per);
    return 0;
}
