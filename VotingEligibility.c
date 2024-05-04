#include <stdio.h>

int main() {
    int age;
    printf("enter age : ");
    scanf("%d", &age);
   
    if (age>=18){
        printf("the citizen is allowed to vote");
    }
else{
    printf("citizen is not allowed to vote");
}
    return 0;
}
