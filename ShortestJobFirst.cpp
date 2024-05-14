#include <iostream>
using namespace std;

struct Process {
    int pid;
    int at;
    int bt;
    int ct, wt, tat, start_time;
};

int main() {
    int n;
    cout << "Enter total number of processes: ";
    cin >> n;

    Process ps[100];
    bool is_completed[100] = {false};
    int current_time = 0;
    int completed = 0;
    int sum_tat = 0, sum_wt = 0, total_idle_time = 0, prev = 0;

    cout << fixed;

    for(int i = 0; i < n; i++) {
        cout << "\nEnter Process " << i +1<< " Arrival Time and Burst Time: \n";
        cin >> ps[i].at >> ps[i].bt;
        ps[i].pid = i;
    }

    while(completed != n) {
        int min_index = -1;
        int minimum = 999;
        for(int i = 0; i < n; i++) {
            if(ps[i].at <= current_time && !is_completed[i]) {
                if(ps[i].bt < minimum) {
                    minimum = ps[i].bt;
                    min_index = i;
                }
                if(ps[i].bt == minimum) {
                    if(ps[i].at < ps[min_index].at) {
                        minimum = ps[i].bt;
                        min_index = i;
                    }
                }
            }
        }

        if(min_index == -1) {
            current_time++;
        } else {
            ps[min_index].start_time = current_time;
            ps[min_index].ct = ps[min_index].start_time + ps[min_index].bt;
            ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
            ps[min_index].wt = ps[min_index].tat - ps[min_index].bt;
            sum_tat += ps[min_index].tat;
            sum_wt += ps[min_index].wt;
            
            total_idle_time += (prev == 0) ? 0 : (ps[min_index].start_time - prev);
            completed++;
            is_completed[min_index] = true;

            current_time = ps[min_index].ct;
            prev = current_time;
        }
    }

    cout << "\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\t\n";
    for(int i = 0; i < n; i++) {
        cout << i +1<< "\t\t\t" << ps[i].at << "\t" << ps[i].bt << "\t\t\t\t" << ps[i].ct << "\t" << ps[i].tat << "\t" << ps[i].wt << "\t" << endl;
    }
    cout << endl;

    return 0;
}
