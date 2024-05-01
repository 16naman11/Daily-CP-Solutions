#include <stdio.h>

int main() {
    char x;
    printf("enter an alphabet : ");
    scanf("%c", &x);
   
    if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
        printf("alphabet is a vowel");
       
    }
    else if (x=='A'||x=='E'||x=='I'||x=='O'||x=='U'){
        printf("alphabet is a vowel");
       
    }
else {
    printf("alphabet is a consonent");
}
    return 0;
}
