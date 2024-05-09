#include <stdio.h>

int main() {
int array[10],smallest,i;

for(i=0;i<10;i++){
    printf("enter value of an integer : ");
    scanf("%d", &array[i]);
    
}

smallest = array[i];
for(i=0;i<=9;i++){
    if(smallest>array[i]){
        smallest=array[i];
    }
}
printf("the smallest integer is %d", smallest);

    return 0;
}
