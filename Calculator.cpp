#include <iostream>
using namespace std;


class calc{
 public:
 int a,b,choice;
 float result;
 
 int get(){
     cout<<"enter integer a and b : \n";
     cin>>a>>b;
     return 0;
 }
 
 int userchoice(){
     cout<<"enter 1 for addition.\n";
     cout<<"enter 2 for subtraction.\n";
     cout<<"enter 3 for multiplication.\n";
     cout<<"enter 4 for division.\n";
     cin>>choice;
     return choice;
 }
 
 float operation(){
     if(choice==1){
       result = a+b;
         cout<<"the result is : "<<result;
     }
     else if(choice == 2){
         result= a-b;
          cout<<"the result is : "<<result;
     }
     else if(choice == 3){
       result =a*b;
          cout<<"the result is : "<<result;
     }
     else if(choice==4){
         result=a/b;
          cout<<"the result is : "<<result;
     }
     else{
         cout<<"the entered choice is incorrect\n";
     }
     return 0;
 }
};



int main() {
    
   calc obj;
   obj.get();
   obj.userchoice();
   obj.operation();

    return 0;
}
