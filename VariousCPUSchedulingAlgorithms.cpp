#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority; // Only for Priority Scheduling
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int remaining_time; // Only for Round Robin
    int response_time; // Only for Round Robin
};

// Function prototypes
void completionTime(Process proc[], int n);
void turnaroundTime(Process proc[], int n);
void waitingTime(Process proc[], int n);
void SJF(Process proc[], int n);
void PriorityScheduling(Process proc[], int n);
void RoundRobin(Process proc[], int n, int quantum);
void printProcesses(Process proc[], int n);
float calculateAverageWaitingTime(Process proc[], int n);
float calculateAverageTurnaroundTime(Process proc[], int n);

int main() {
    int n;
    int quantum;

    cout << "Enter the number of processes: ";
    cin >> n;

    // Define processes
    vector<Process> proc(n);
    for (int i = 0; i < n; ++i) {
        cout << "Process " << i + 1 << ":\n";
        proc[i].pid = i + 1;
        cout << "Arrival Time: ";
        cin >> proc[i].arrival_time;
        cout << "Burst Time: ";
        cin >> proc[i].burst_time;
    }

    cout << "Enter the time quantum for Round Robin: ";
    cin >> quantum;

    // FCFS
    completionTime(&proc[0], n);
    turnaroundTime(&proc[0], n);
    waitingTime(&proc[0], n);
    float avg_waiting_fcfs = calculateAverageWaitingTime(&proc[0], n);
    float avg_turnaround_fcfs = calculateAverageTurnaroundTime(&proc[0], n);

    // SJF
    SJF(&proc[0], n);
    float avg_waiting_sjf = calculateAverageWaitingTime(&proc[0], n);
    float avg_turnaround_sjf = calculateAverageTurnaroundTime(&proc[0], n);

    // Priority Scheduling
    cout << "For priority scheduling enter the required priorities:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Enter priority for Process " << i + 1 << ": ";
        cin >> proc[i].priority;
    }
    PriorityScheduling(&proc[0], n);
    float avg_waiting_priority = calculateAverageWaitingTime(&proc[0], n);
    float avg_turnaround_priority = calculateAverageTurnaroundTime(&proc[0], n);

    // Round Robin
    RoundRobin(&proc[0], n, quantum);
    float avg_waiting_rr = calculateAverageWaitingTime(&proc[0], n);
    float avg_turnaround_rr = calculateAverageTurnaroundTime(&proc[0], n);

    // Print results
    cout << "\nAverage Waiting Time:\n";
    cout << "----------------------------------\n";
    cout << "      Algorithm    Value\n";
    cout << "----------------------------------\n";
    cout << "           FCFS" << setw(12) << avg_waiting_fcfs << endl;
    cout << "            SJF" << setw(12) << avg_waiting_sjf << endl;
    cout << "       Priority" << setw(12) << avg_waiting_priority << endl;
    cout << "    Round Robin" << setw(12) << avg_waiting_rr << endl;
    cout << "----------------------------------\n\n";

    cout << "Average Turnaround Time:\n";
    cout << "----------------------------------\n";
    cout << "      Algorithm    Value\n";
    cout << "----------------------------------\n";
    cout << "           FCFS" << setw(12) << avg_turnaround_fcfs << endl;
    cout << "            SJF" << setw(12) << avg_turnaround_sjf << endl;
    cout << "       Priority" << setw(12) << avg_turnaround_priority << endl;
    cout << "    Round Robin" << setw(12) << avg_turnaround_rr << endl;
    cout << "----------------------------------\n\n";

    // Determine the best scheduling algorithm
    cout << "Best Scheduling Algorithm based on Average Waiting Time: ";
    if (avg_waiting_fcfs <= avg_waiting_sjf && avg_waiting_fcfs <= avg_waiting_priority && avg_waiting_fcfs <= avg_waiting_rr)
        cout << "FCFS\n";
    else if (avg_waiting_sjf <= avg_waiting_fcfs && avg_waiting_sjf <= avg_waiting_priority && avg_waiting_sjf <= avg_waiting_rr)
        cout << "SJF\n";
    else if (avg_waiting_priority <= avg_waiting_fcfs && avg_waiting_priority <= avg_waiting_sjf && avg_waiting_priority <= avg_waiting_rr)
        cout << "Priority\n";
    else
        cout << "Round Robin\n";

    cout << "Best Scheduling Algorithm based on Average Turnaround Time: ";
    if (avg_turnaround_fcfs <= avg_turnaround_sjf && avg_turnaround_fcfs <= avg_turnaround_priority && avg_turnaround_fcfs <= avg_turnaround_rr)
        cout << "FCFS\n";
    else if (avg_turnaround_sjf <= avg_turnaround_fcfs && avg_turnaround_sjf <= avg_turnaround_priority && avg_turnaround_sjf <= avg_turnaround_rr)
        cout << "SJF\n";
    else if (avg_turnaround_priority <= avg_turnaround_fcfs && avg_turnaround_priority <= avg_turnaround_sjf && avg_turnaround_priority <= avg_turnaround_rr)
        cout << "Priority\n";
    else
        cout << "Round Robin\n";

    return 0;
}

void completionTime(Process proc[], int n) {
    proc[0].completion_time = proc[0].arrival_time + proc[0].burst_time;
    for (int i = 1; i < n; i++) {
        proc[i].completion_time = max(proc[i - 1].completion_time, proc[i].arrival_time) + proc[i].burst_time;
    }
}

void turnaroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turn_around_time = proc[i].completion_time - proc[i].arrival_time;
    }
}

void waitingTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;
    }
}
void SJF(Process proc[], int n) {
    // Sort processes by arrival time initially to handle ties
    sort(proc, proc + n, [](Process a, Process b) {
        return a.arrival_time < b.arrival_time;
    });

    // Keep track of which processes have arrived
    vector<bool> arrived(n, false);
    int completed_processes = 0;
    int time = 0;

    while (completed_processes < n) {
        int shortest_burst_index = -1;
        int shortest_burst_time = INT_MAX;

        // Find the process with the shortest burst time among the arrived processes
        for (int i = 0; i < n; ++i) {
            if (!arrived[i] && proc[i].arrival_time <= time && proc[i].burst_time < shortest_burst_time) {
                shortest_burst_time = proc[i].burst_time;
                shortest_burst_index = i;
            }
        }

        if (shortest_burst_index == -1) {
            // If no process has arrived yet, move time forward to the next arrival
            time = proc[completed_processes].arrival_time;
        } else {
            // Update the time and process execution
            time += proc[shortest_burst_index].burst_time;
            proc[shortest_burst_index].completion_time = time;
            arrived[shortest_burst_index] = true;
            completed_processes++;
        }
    }

    // Calculate turnaround time and waiting time
    turnaroundTime(proc, n);
    waitingTime(proc, n);
}


// void SJF(Process proc[], int n) {
//     sort(proc, proc + n, [](Process a, Process b) {
//         return a.burst_time < b.burst_time;
//     });
//     completionTime(proc, n);
//     turnaroundTime(proc, n);
//     waitingTime(proc, n);
// }

void PriorityScheduling(Process proc[], int n) {
    sort(proc, proc + n, [](Process a, Process b) {
        return a.priority < b.priority;
    });
    completionTime(proc, n);
    turnaroundTime(proc, n);
    waitingTime(proc, n);
}
void RoundRobin(Process proc[], int n, int quantum) {
    vector<int> remaining_time(n); // Track remaining time for each process
    int current_time = 0; // Current time

    // Initialize remaining time for each process
    for (int i = 0; i < n; ++i) {
        remaining_time[i] = proc[i].burst_time;
    }

    // Round Robin scheduling loop
    while (true) {
        bool all_processes_done = true; // Flag to check if all processes are done in this time quantum

        // Traverse each process
        for (int i = 0; i < n; ++i) {
            if (remaining_time[i] > 0) {
                all_processes_done = false; // At least one process is remaining

                // Execute the process for the minimum of quantum or remaining time
                int execute_time = min(quantum, remaining_time[i]);
                current_time += execute_time;
                remaining_time[i] -= execute_time;

                // If the process completes within this time quantum
                if (remaining_time[i] == 0) {
                    // Set the completion time if not already set
                    if (proc[i].completion_time == 0) {
                        proc[i].completion_time = current_time;
                    }
                }
            }
        }

        // If all processes are done, exit the loop
        if (all_processes_done) {
            break;
        }
    }

    // Calculate turnaround time (TAT) and waiting time (WT) for each process
    for (int i = 0; i < n; ++i) {
        proc[i].turn_around_time = proc[i].completion_time - proc[i].arrival_time;
        proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;
    }
}


// void RoundRobin(Process proc[], int n, int quantum) {
//     queue<int> q;
//     vector<bool> inQueue(n, false); // Track which processes are in the queue
//     int time = 0;
//     int remaining_processes = n;

//     for (int i = 0; i < n; i++) {
//         proc[i].remaining_time = proc[i].burst_time;
//         proc[i].response_time = -1; // Initialize response time to -1
//     }

//     // Start with the first process
//     q.push(0);
//     inQueue[0] = true;

//     while (!q.empty()) {
//         int i = q.front();
//         q.pop();
//         inQueue[i] = false;

//         // Update response time if the process is being handled for the first time
//         if (proc[i].response_time == -1) {
//             proc[i].response_time = time - proc[i].arrival_time;
//         }

//         if (proc[i].remaining_time <= quantum) {
//             time += proc[i].remaining_time;
//             proc[i].remaining_time = 0;
//             proc[i].completion_time = time;
//             remaining_processes--;
//         } else {
//             time += quantum;
//             proc[i].remaining_time -= quantum;
//         }

//         // Push newly arrived processes into the queue
//         for (int j = 0; j < n; j++) {
//             if (proc[j].arrival_time <= time && proc[j].remaining_time > 0 && !inQueue[j]) {
//                 q.push(j);
//                 inQueue[j] = true;
//             }
//         }

//         // Reinsert the current process if it's not finished yet
//         if (proc[i].remaining_time > 0) {
//             q.push(i);
//             inQueue[i] = true;
//         }
//     }

//     turnaroundTime(proc, n);
//     waitingTime(proc, n);
// }

float calculateAverageWaitingTime(Process proc[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += proc[i].waiting_time;
    }
    return sum / n;
}

float calculateAverageTurnaroundTime(Process proc[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += proc[i].turn_around_time;
    }
    return sum / n;
}

// void printProcesses(Process proc[], int n) {
//     cout << "PID\tArrival time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n";
//     for (int i = 0; i < n; i++) {
//         cout << proc[i].pid << "\t" << proc[i].arrival_time << "\t\t" << proc[i].burst_time << "\t\t" << proc[i].completion_time << "\t\t" << proc[i].turn_around_time << "\t\t" << proc[i].waiting_time;
//         if (proc[i].response_time != -1)
//             cout << "\t\t" << proc[i].response_time;
//         cout << endl;
//     }
// }