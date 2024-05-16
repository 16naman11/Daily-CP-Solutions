#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of tasks: ";
    cin >> n;
    float p[n][3];

    cout << "Enter the profit and weight of each task respectively:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Task " << i+1 << ": ";
        cin >> p[i][0] >> p[i][1];
        p[i][2] = p[i][0] / p[i][1];
    }

    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (p[i][2] < p[j][2]) {
                swap(p[i], p[j]);
            }
        }
    }

    float w;
    cout << "Enter the maximum capacity of the bag: ";
    cin >> w;

    int j = 0;
    float profit = 0;
    while (w > 0 && j < n) {
        if (p[j][1] <= w) {
            profit += p[j][0];
            w -= p[j][1];
            j++;
        } else {
            profit += (w * p[j][2]);
            w = 0;
        }
    }
    cout << "The maximum profit that could be earned is " << profit << endl;
    return 0;
}
