#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20], response[20];

    for(int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for P" << i+1 << ": ";
        cin >> at[i] >> bt[i];

        rt[i] = bt[i];
        response[i] = -1;
    }

    int time = 0;
    int completed = 0;

    cout << "\nGantt Chart:\n";

    while(completed < n) {

        int pos = -1;
        int shortest = 9999;

        // Find process with shortest remaining time
        for(int i = 0; i < n; i++) {

            if(at[i] <= time && rt[i] > 0) {

                if(rt[i] < shortest) {
                    shortest = rt[i];
                    pos = i;
                }
            }
        }

        // If no process has arrived
        if(pos == -1) {
            time++;
            continue;
        }

        // First response
        if(response[pos] == -1)
            response[pos] = time - at[pos];

        cout << "| P" << pos+1 << " ";

        // Run for 1 unit
        rt[pos]--;
        time++;

        // Process completed
        if(rt[pos] == 0) {
            ct[pos] = time;
            completed++;
        }
    }

    cout << "|\n";

    float avgTAT = 0;
    float avgWT = 0;
    float avgRT = 0;

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";

    for(int i = 0; i < n; i++) {

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgTAT += tat[i];
        avgWT += wt[i];
        avgRT += response[i];

        cout << "P" << i+1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\t"
             << response[i] << endl;
    }

    cout << "\nAverage Turnaround Time = "
         << avgTAT/n;

    cout << "\nAverage Waiting Time = "
         << avgWT/n;

    cout << "\nAverage Response Time = "
         << avgRT/n;

    return 0;
}