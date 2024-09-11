#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of object: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter weight and value of each object:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Enter details for object " << i+1 << ": ";
        cin >> weights[i] >> values[i];
    }

    int w;
    cout << "Enter the size of the knapsack: ";
    cin >> w;

    vector<vector<int>> t(n+1, vector<int>(w+1, 0));
    
    cout<<"the D.P. table is: \n\n";

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= w; ++j) {
            if(i==0||j==0){
                cout<<"0\t";
                continue;
            }
            if (weights[i-1] <= j) {
                t[i][j] = max(t[i-1][j], values[i-1] + t[i-1][j - weights[i-1]]);
            } else {
                t[i][j] = t[i-1][j];
            }
            cout << t[i][j] << "\t"; 
        }
        cout << "\n"; 
    }

    cout << "\n\nMaximum value in knapsack: " << t[n][w] << endl;
    
    int res = t[n][w];
    int w_temp = w;
    cout << "\nobjects included in the knapsack : ";

    for (int i = n; i > 0 && res > 0; i--) {
        if (res == t[i-1][w_temp]) {
            continue;
        } else {
            cout << i << " "; 
            res -= values[i-1];
            w_temp -= weights[i-1];
        }
    }
    cout << endl;

    return 0;
}
