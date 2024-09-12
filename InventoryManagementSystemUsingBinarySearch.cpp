#include <iostream>
#include <string>

using namespace std;

struct Product {
    int id;
    string name;
    float price;
    int quantity;
};

// Function to perform binary search
int binarySearch(Product arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[mid].id == x) {
            // If quantity of the product is more than 0, return its index
            if (arr[mid].quantity > 0)
                return mid;
            else
                return -1; // Quantity is 0
        }

        // If x greater, ignore left half
        if (arr[mid].id < x)
            l = mid + 1;

        // If x is smaller, ignore right half
        else
            r = mid - 1;
    }

    // if we reach here, then element was not present
    return -1;
}

int main() {
    
    Product inventory[10];
    for (int i = 0; i < 10; ++i) {
        inventory[i].id = 100 + i;
        cout << "Enter name for product with ID " << inventory[i].id << ": ";
        cin >> inventory[i].name;
        cout << "Enter price for product with ID " << inventory[i].id << ": ";
        cin >> inventory[i].price;
        cout << "Enter quantity for product with ID " << inventory[i].id << ": ";
        cin >> inventory[i].quantity;
        cout<<endl;
    }

    int productId;
    cout << "Enter the product ID to search: ";
    cin >> productId;

    int index = binarySearch(inventory, 0, 9, productId);

    if (index != -1) {
        cout << "Product with ID " << productId << " is available.\n Quantity : "<<inventory[productId -100].quantity << endl;
        cout<<"do you want to update the quantity?(Y/N)"<<endl;
        char reply;
        int quant;
        cin>>reply;
        if(reply=='Y'){
            cout<<"enter the new quantity : "<<endl;
            cin>>quant;
            inventory[productId -100].quantity+=quant;
            cout<<"the updated quantity is "<<inventory[productId -100].quantity<<endl;
        }
        
    } else {
        cout << "Product with ID " << productId << " is not available or quantity is 0." << endl;
    }
    

    return 0;
}