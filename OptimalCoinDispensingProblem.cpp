/*greedy strategy*/


#include <iostream>
#include <vector>

using namespace std;

void makeChange(int billAmount, int cashGiven) {
    int denominations[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int numDenominations = sizeof(denominations) / sizeof(denominations[0]);

    int change = cashGiven - billAmount;

    for (int i = 0; i < numDenominations; ++i) {
        int numBills = change / denominations[i];
        change -= numBills * denominations[i];
        if (numBills > 0) {
            if (denominations[i] >= 10) {
                cout << "Dispense " << numBills << " x Rs." << denominations[i] << " bill(s)" << endl;
            } else {
                cout << "Dispense " << numBills << " x Rs." << denominations[i] << " coin(s)" << endl;
            }
        }
        if (change == 0) {
            break;
        }
    }
}

void billdesk() {
    cout << "List of Articles:" << endl;
    cout << "1. Oreo: Rs.30" << endl;
    cout << "2. Chips: Rs.10" << endl;
    cout << "3. Coca-Cola: Rs.15" << endl;
    cout << "4. Snickers: Rs.30" << endl;
    cout << "5. Doritos: Rs.20" << endl;
    cout << "6. Pepsi: Rs.12" << endl;
    cout << "7. KitKat: Rs.25" << endl;
    cout << "8. Mountain Dew: Rs.32" << endl;
    cout << "9. Lays: Rs.15" << endl;
    cout << "10. Twix: Rs.40" << endl;
    cout << "Enter 0 to exit billing" << endl<< endl;
}

void billingProcess() {
    int totalBill = 0;
    int itemNumber;
    
    while (true) {
        cout << "Enter item number: ";
        cin >> itemNumber;

        if (itemNumber == 0) {
            break;
        }

        int prices[] = {30, 10, 15, 30, 20, 12, 25, 32, 15, 40};

        if (itemNumber < 0 || itemNumber > 10) {
            cout << "Invalid item number. Please enter a number between 1 and 10." << endl;
            continue;
        }

        totalBill += prices[itemNumber - 1];
    }

    cout <<endl<< "Total bill amount: Rs." << totalBill << endl;

    int cashGiven;
    cout << "Enter cash bill: Rs.";
    cin >> cashGiven;

    cout << endl << "Change Breakdown:" << endl;
    makeChange(totalBill, cashGiven);
}

int main() {
    billdesk();
    billingProcess();

    return 0;
}
