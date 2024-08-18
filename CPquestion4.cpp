/*random number matching game*/


#include <stdio.h>

int main() {
    int a,diff,ans;
    printf("Welcome to the game of guessing numbers\n");
    printf("Guess a number between 1 and 100 : ");
    scanf("%d", &a);
    ans=rand()%100;
    while(a!=ans){
        
        diff=ans-a;
        if(diff>0){
            printf("input too low!! try again\n");
        }
        else{
            printf("input too high!! try again\n");
        }
        printf("Guess a number again : ");
        scanf("%d", &a);
    }
    printf("answer is correct !!! congratulations, the answer is %d !", ans);
    return 0;
}
