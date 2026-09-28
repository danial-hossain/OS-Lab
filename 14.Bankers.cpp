#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    // Allocation
    int A[20], B[20], C[20];

    // Maximum
    int maxA[20], maxB[20], maxC[20];

    // Available
    int avA, avB, avC;

    cout << "\nEnter Allocation (A B C):\n";

    for(int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i] >> C[i];
    }

    cout << "\nEnter Max (A B C):\n";

    for(int i = 0; i < n; i++)
    {
        cin >> maxA[i] >> maxB[i] >> maxC[i];
    }

    cout << "\nEnter Available (A B C): ";
    cin >> avA >> avB >> avC;


    bool finish[20] = {false};
    int safe[20];
    int count = 0;


    while(count < n)
    {
        bool found = false;

        // P0 থেকে check করবে
        // যেটা আগে পাবে সেটাই আগে যাবে
        for(int i = 0; i < n; i++)
        {
            if(finish[i] == false)
            {
                // Remaining Need
                int needA = maxA[i] - A[i];
                int needB = maxB[i] - B[i];
                int needC = maxC[i] - C[i];

                // Need <= Available ?
                if(needA <= avA &&
                   needB <= avB &&
                   needC <= avC)
                {
                    cout << "\nP" << i << " gets the resources";

                    // Process finishes
                    avA = avA + A[i];
                    avB = avB + B[i];
                    avC = avC + C[i];

                    cout << "\nAvailable = "
                         << avA << " "
                         << avB << " "
                         << avC << endl;

                    safe[count] = i;
                    count++;

                    finish[i] = true;
                    found = true;
                }
            }
        }

        // কোনো process-ই যদি না পায়
        if(found == false)
        {
            break;
        }
    }


    if(count == n)
    {
        cout << "\nSystem is in SAFE state.";

        cout << "\nSafe Sequence: ";

        for(int i = 0; i < n; i++)
        {
            cout << "P" << safe[i];

            if(i != n-1)
                cout << " -> ";
        }

        cout << endl;
    }
    else
    {
        cout << "\nSystem is in UNSAFE state.";
    }

    return 0;
}