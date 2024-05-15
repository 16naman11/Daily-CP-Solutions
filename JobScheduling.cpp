#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    int j[n][2];

    cout << "Enter the deadline followed by the profit of each job respectively: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Job " << i+1 << " : " << endl;
        cin >> j[i][0] >> j[i][1];
    }

    
    for (int i = 0; i < n; ++i) {
        for (int z = i + 1; z < n; ++z) {
            if (j[z][1] > j[i][1]) {
                swap(j[i], j[z]);
            }
        }
    }

   
    int maxdead = 0;
    for (int i = 0; i < n; ++i) {
        if (maxdead < j[i][0]) {
            maxdead = j[i][0];
        }
    }

    
    int gantt[maxdead] = {0}; 

    for (int i = 0; i < n; ++i) {
        for (int y = j[i][0] - 1; y >= 0; --y) {
            if (gantt[y] == 0) {
                gantt[y] = j[i][1];
                break;
            }
        }
    }

    
    int profit = 0;
    for (int i = 0; i < maxdead; ++i) {
        profit += gantt[i];
    }

    cout << "The maximum profit that could be earned is: " << profit << endl;

    return 0;
}
