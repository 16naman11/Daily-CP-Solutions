#include <iostream>

class MyClass {
public:
    int value;

    // Parameterized constructor
    MyClass(int val) {
        value = val;
    }
};

int main() {
    // Create an object of MyClass with value 10
    MyClass obj(10);

    // Print the value
    std::cout << "Value: " << obj.value << std::endl;

    return 0;
}