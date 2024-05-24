#include <stdio.h>
int main() {
   char ch;
   printf("enter an alphabet : ");
   scanf("%c", &ch);
   if(ch>='a'&&ch<='z'){
       printf("alphabet is in lower case");
   }
   else{
       printf("alphabet is in upper case");
   }
    return 0;
}
