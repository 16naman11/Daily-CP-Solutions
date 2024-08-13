#include <stdio.h>

void main(){
    int a[100],low,high,key,n,flag,i;
    printf("enter the size of the array : \n");
    scanf("%d",&n);
    printf("enter the elements of the array :\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    low=0;
    high=n-1;
    printf("enter the key : ");
    scanf("%d",&key);
    flag=binarysearch(a,low,high,key);
    if(flag==1){
        printf("element found");
    }
    else{
        printf("element not found.");
    }
}
int binarysearch(int a[100],int low, int high, int key){
    if (high>=low){
        int mid=(low+high)/2;
        if(a[mid]==key){
            return 1;
        }
        else if(a[mid]>key){
            return binarysearch(a,low,mid-1,key);
        }
        else{
            return binarysearch(a,mid+1,high,key);
        }
        return -1;
    }
}
