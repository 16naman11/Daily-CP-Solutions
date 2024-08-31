#include <iostream>
using namespace std;

class coordinate
{
    int a;
    public:
    coordinate(int t){
        a=t;
    }
    coordinate(coordinate &x){
        a=x.a;
    }
    void show(){
        cout<<a<<endl;
    }
};
int main() {
    int x;
    cout<<"enter a: ";
    cin>>x;
    coordinate obj1(x);
    coordinate obj2(obj1);
    cout<<"value of a : ";
    obj1.show();
    cout<<"value of a after copying : ";
    obj2.show();
   return 0;
}
