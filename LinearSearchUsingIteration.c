#include <stdio.h>
int linearsearch(int a[], int n, int key);
void main(){
    int a[100],key,n,flag,i;
    printf("enter the size of the array : \n");
    scanf("%d",&n);
    printf("enter the elements of the array :\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the key : ");
    scanf("%d",&key);
    flag=linearsearch(a,i,key);
    if(flag==1){
        printf("element found");
    }
    else{
        printf("element not found.");
    }
}
int linearsearch(int a[],int n,int key){
    for(int i=0;i<n;i++){
        if(key==a[i]){
            return 1;
        }
    }
    return -1;
}
