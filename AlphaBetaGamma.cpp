//Alpha beta gamma


#include <iostream>
using namespace std;
class alpha {
    public :
    int x;
    void getx(){
        cout<<"enter value of x : ";
        cin>>x;
    }
};
class beta{
    public :
    int y;
    void gety(){
        cout<<"enter value of y : ";
        cin>>y;
    }
};
class gamma : public alpha, public beta{
    public:
    void show(){
        cout<<"x is "<<x<<endl;
        cout<<"y is "<<y<<endl;
        
    }
};

int main() {
   gamma obj;
   obj.getx();
   obj.gety();
   obj.show();
    return 0;
}
