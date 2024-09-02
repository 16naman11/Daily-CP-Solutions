/*Consider a class ‘Vehicle’ which has a derive class ‘Fourwheeler’ and ‘Fourwheeler’ also has a
derived class ‘Car’. Class ‘Vehicle’ has data members category and reg_no. ‘Fourwheeler’ has
data members model_no, isuue_year, and company. Compute the program to print their
properties using multilevel inheritance.*/





#include <iostream>
using namespace std;
 
class vehicle{
    public:
    string cat;
    int reg_no;
    void get(){
        cout<<"enter category\n";
        cin>>cat;
        cout<<"Enter the registration number : \n";
        cin>>reg_no;
    }
};

class fourwheeler : public vehicle{
    public:
    string model_no;
    int issue_year;
    string company;
    void put(){
        
        cout<<"enter the model number : ";
        cin>>model_no;
        cout<<"enter company \n";
        cin>>company;
    }
};

class car : public fourwheeler{
    public:
    void show(){
        cout<<"\n\n\n";
        cout<<"category : "<<cat<<endl;
        cout<<"Registration number : "<<reg_no<<endl;
        cout<<"Model number : "<<model_no<<endl;
        cout<<"Company name : "<<company;
    }
};
int main() {
   car obj;
   obj.get();
   obj.put();
   obj.show();
    return 0;
}
