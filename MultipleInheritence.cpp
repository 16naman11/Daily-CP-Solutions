
#include<iostream>
using namespace std;
class person{
public:
string name;
void get(){
cout<<"Enter name : "; 
cin>>name;
    
}

};
class employee{
public:
int id;
void put(){
cout<<"Enter employee id : ";
cin>>id;
}
};

class manager: public person, public employee{
public:
int no;
void getdata(){
cout<<"Enter contact no: "; cin>>no;
}
void show(){
cout<<"Employee name: "<<name<<endl;
cout<<"Employee id: "<<id<<endl;
cout<<"Employee contact no : "<<no;
}
};
int main(){ 
    manager obj;

obj.get(); 
obj.put();
obj.getdata(); 
obj.show();

return 0;

}
