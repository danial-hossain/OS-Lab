#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int AT[20], BT[20];
    int CT[20], TAT[20], WT[20], RT[20];
    int done[20] = {0};

    // Input
    for(int i = 0; i < n; i++)
    {
        cout << "Enter AT and BT for P" << i + 1 << ": ";
        cin >> AT[i] >> BT[i];
    }

    int time = 0;
    int completed = 0;

    cout << "\nGantt Chart:\n";

    while(completed < n)
    {
        int pos = -1;
        int small = 9999;

        // Find shortest job
        for(int i = 0; i < n; i++)
        {
            if(AT[i] <= time && done[i] == 0)
            {
                if(BT[i] < small)
                {
                    small = BT[i];
                    pos = i;
                }
            }
        }

        // CPU idle
        if(pos == -1)
        {
            time++;
            continue;
        }

        // Response Time
        RT[pos] = time - AT[pos];

        cout << "| P" << pos + 1 << " ";

        // Process runs completely
        time = time + BT[pos];

        // Completion Time
        CT[pos] = time;

        done[pos] = 1;
        completed++;
    }

    cout << "|\n";

    float sumTAT = 0;
    float sumWT = 0;
    float sumRT = 0;

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";

    for(int i = 0; i < n; i++)
    {
        // Turnaround Time
        TAT[i] = CT[i] - AT[i];

        // Waiting Time
        WT[i] = TAT[i] - BT[i];

        sumTAT = sumTAT + TAT[i];
        sumWT = sumWT + WT[i];
        sumRT = sumRT + RT[i];

        cout << "P" << i + 1 << "\t"
             << AT[i] << "\t"
             << BT[i] << "\t"
             << CT[i] << "\t"
             << TAT[i] << "\t"
             << WT[i] << "\t"
             << RT[i] << endl;
    }

    cout << "\nAverage TAT = " << sumTAT / n;
    cout << "\nAverage WT  = " << sumWT / n;
    cout << "\nAverage RT  = " << sumRT / n;

    return 0;
}
