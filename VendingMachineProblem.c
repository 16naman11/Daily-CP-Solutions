#include <stdio.h>

int main() {
    printf("--------welcome to ticket vending machine--------\n");
    int i,choice,noc=0,nocr=0,nom=0,crtotal=0,mtotal=0,ctotal=0,tickets=0,total=0;
    printf("Enter 1 for buying movie tickets.\n");
    printf("Enter 2 for buying concert tickets.\n");
    printf("Enter 3 for buying sports tickets.\n");
    printf("Enter 0 when you want to end purchase\n");
    for(i=0;i<3;i++){
        printf("enter your choice : ");
        scanf("%d", &choice);
        if(choice==1){
            printf("JAWAAN\n show time 9:30 P.M.\n price - Rs. 250\n");
            printf("how many movie tickets would you like to purchase : ");
            scanf("%d", &nom);
            mtotal=nom*250;
        }
        else if(choice==2){
            printf("ARIJIT SINGH\n show time 9:30 P.M.\n price - Rs. 1000\n");
            printf("how many concert tickets would you like to purchase : ");
            scanf("%d", &noc);
            ctotal=noc*1000;
        }
        else if(choice==3){
            printf("IND VS AUS\n match time 9:30 A.M.\n price - Rs. 3000\n");
            printf("how many movie tickets would you like to purchase : ");
            scanf("%d", &nocr);
            crtotal=nocr*3000;
        }
        else if(choice==0){
            break;
        }
    }
    tickets=nom+noc+nocr;
    total=crtotal+ctotal+mtotal;
    printf("your total for the %d tickets is Rs.%d",tickets,total);

    return 0;
}
