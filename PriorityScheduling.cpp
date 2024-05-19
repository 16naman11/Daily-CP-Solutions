#include <iostream>
#include <climits>

using namespace std;

void bubbleSort(int processes[], int burst_time[], int arrival_time[], int priority[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival_time[j] > arrival_time[j + 1]) {
                swap(processes[j], processes[j + 1]);
                swap(burst_time[j], burst_time[j + 1]);
                swap(arrival_time[j], arrival_time[j + 1]);
                swap(priority[j], priority[j + 1]);
            }
        }
    }
}

void calculateTimes(int processes[], int n, int burst_time[], int arrival_time[], int priority[]) {
    bubbleSort(processes, burst_time, arrival_time, priority, n);

    int completion_time[n];
    int waiting_time[n];
    int turnaround_time[n];
    int executed[n] = {0};

    completion_time[0] = burst_time[0] + arrival_time[0]; // Update to include arrival time
    turnaround_time[0] = completion_time[0] - arrival_time[0];
    waiting_time[0] = turnaround_time[0] - burst_time[0];
    executed[0] = 1;

    for (int i = 1; i < n; i++) {
        int shortest = -1;
        int min_priority = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (arrival_time[j] <= completion_time[i - 1] && !executed[j] && priority[j] < min_priority) {
                shortest = j;
                min_priority = priority[j];
            }
        }

        if (shortest != -1) {
            completion_time[i] = completion_time[i - 1] + burst_time[shortest];
            turnaround_time[shortest] = completion_time[i] - arrival_time[shortest];
            waiting_time[shortest] = turnaround_time[shortest] - burst_time[shortest];
            executed[shortest] = 1;
        }
    }

    float total_turnaround_time = 0, total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround_time += turnaround_time[i];
        total_waiting_time += waiting_time[i];
    }
    float avg_turnaround_time = total_turnaround_time / n;
    float avg_waiting_time = total_waiting_time / n;

    // Printing the completion time for each process ID according to their completion order
cout << "Process\tA.T.\tB.T.\tPriority\tC.T.\tT.A.T.\tW.T.\n";
for (int i = 0; i < n; i++) {
    // Find the index of the process with the corresponding completion time
    int index = -1;
    for (int j = 0; j < n; j++) {
        if (completion_time[j] == completion_time[i]) {
            index = j;
            break;
        }
    }
    cout << processes[index] << "\t\t" << arrival_time[index] << "\t\t" << burst_time[index] << "\t\t" << priority[index] << "\t\t" 
    << completion_time[index] << "\t\t\t" << turnaround_time[index] << "\t\t\t" << waiting_time[index] << "\n";
}

    cout << "Average Turnaround Time: " << avg_turnaround_time << "\n";
    cout << "Average Waiting Time: " << avg_waiting_time << "\n";
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int processes[n];
    int burst_time[n];
    int arrival_time[n];
    int priority[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Process ID for Process " << i + 1 << ": ";
        cin >> processes[i];
        cout << "Enter Arrival Time for Process " << i + 1 << ": ";
        cin >> arrival_time[i];
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> burst_time[i];
        cout << "Enter Priority for Process " << i + 1 << ": ";
        cin >> priority[i];
    }

    calculateTimes(processes, n, burst_time, arrival_time, priority);

    return 0;
}