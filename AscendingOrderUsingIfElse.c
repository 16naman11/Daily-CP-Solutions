#include <stdio.h>

int main() {
    int a,b,c;
    printf("enter 3 integers: \n");
    scanf("%d %d %d",&a,&b,&c);
    
    if(a>b&&a>c){
        if(b>c)
        printf("ascending order is %d > %d > %d",c,b,a);
        else
        printf("ascending order is %d > %d > %d",b,c,a);
    }
    else if(b>a&&b>c){
        if(a>c)
        printf("ascending order is %d > %d > %d",c,a,b);
        else
        printf("ascending order is %d > %d > %d",a,c,b);
    }
    else if(c>a&&c>b){
        if(a>b)
        printf("ascending order is %d > %d > %d",b,a,c);
        else
        printf("ascending order is %d > %d > %d",a,b,c);
    }
    return 0;
}
