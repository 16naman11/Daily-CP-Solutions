#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of jobs to be scheduled: " << endl;
    cin >> n;

    int table[n][2]; // Change the size of the table to 2 since each task has 2 elements (arrival time and burst time)

    cout << "Enter the arrival time and burst time of the tasks respectively in milliseconds: " << endl << endl;
    
    for(int i = 0; i < n; i++) { // Start the loop from 0
        cout << "Task " << i + 1 << ": ";
        cin >> table[i][0] >> table[i][1];
    }
    cout << endl;
    
    // Sort tasks based on arrival time
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (table[i][0] > table[j][0]) {
                swap(table[i], table[j]);
            }
        }
    }
    
    cout << "Task\tA.T.\tB.T.\tC.T.\tT.A.T.\tW.T." << endl;
    int ct = 0;
    int total_tat = 0, total_wt = 0;
    for(int i = 0; i < n; i++) {
        int tat = 0, wt = 0;
        cout << i + 1 << "\t\t" << table[i][0] << "\t\t" << table[i][1] << "\t\t";
        if (table[i][0] > ct) {
            ct = table[i][0] + table[i][1];
            cout << ct << "\t\t";
        } else {
            ct += table[i][1];
            cout << ct << "\t\t";
        }
        tat = ct - table[i][0];
        wt = tat - table[i][1];
        total_tat += tat;
        total_wt += wt;
        cout << tat << "\t\t" << wt << endl;
    }
    
    // Output average turnaround time and average waiting time
    cout << "\nAverage Turnaround Time: " << (float)total_tat / n << " milliseconds" << endl;
    cout << "Average Waiting Time: " << (float)total_wt / n << " milliseconds" << endl;

    return 0;
}
