#include <stdio.h>

int main() {
    char one ;
    printf("enter a character : ");
    scanf("%c", &one);
    if((one>='a'&& one<='z')||(one>='A'&&one<='Z')){
        printf("%c is an alphabet", one);
       
    }
    else{
        printf("%c is not an alphabet", one);
    }

    return 0;
}
