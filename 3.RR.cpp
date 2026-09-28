
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, q;

    cout << "Enter number of processes: ";
    cin >> n;

    int AT[20], BT[20], rem[20];
    int CT[20], TAT[20], WT[20], RT[20];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter AT and BT for P" << i + 1 << ": ";
        cin >> AT[i] >> BT[i];

        rem[i] = BT[i];
        RT[i] = -1;
    }

    cout << "Enter Quantum Time: ";
    cin >> q;

    queue<int> ready;

    int time = 0;
    int complete = 0;
    bool added[20] = {false};

    cout << "\nGantt Chart:\n";

    while(complete < n)
    {
        // নতুন আসা process queue-তে ঢুকবে
        for(int i = 0; i < n; i++)
        {
            if(AT[i] <= time && !added[i])
            {
                ready.push(i);
                added[i] = true;
            }
        }

        // Queue empty হলে CPU idle
        if(ready.empty())
        {
            time++;
            continue;
        }

        // Queue থেকে প্রথম process বের করি
        int pos = ready.front();
        ready.pop();

        // Response Time
        if(RT[pos] == -1)
            RT[pos] = time - AT[pos];

        cout << "| P" << pos + 1 << " ";

        // Quantum অনুযায়ী চালানো
        if(rem[pos] > q)
        {
            time = time + q;
            rem[pos] = rem[pos] - q;
        }
        else
        {
            time = time + rem[pos];
            rem[pos] = 0;

            CT[pos] = time;
            complete++;
        }

        // এই সময়ের মধ্যে নতুন process এলে queue-তে ঢুকবে
        for(int i = 0; i < n; i++)
        {
            if(AT[i] <= time && !added[i])
            {
                ready.push(i);
                added[i] = true;
            }
        }

        // Process শেষ না হলে queue-এর শেষে যাবে
        if(rem[pos] > 0)
        {
            ready.push(pos);
        }
    }

    cout << "|\n";

    float sumTAT = 0;
    float sumWT = 0;
    float sumRT = 0;

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";

    for(int i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];

        WT[i] = TAT[i] - BT[i];

        sumTAT += TAT[i];
        sumWT += WT[i];
        sumRT += RT[i];

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
