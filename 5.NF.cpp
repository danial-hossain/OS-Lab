#include <iostream>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter number of blocks: ";
    cin >> n;

    int block[20];

    cout << "Enter block sizes:\n";
    for(int i = 0; i < n; i++)
        cin >> block[i];

    cout << "Enter number of processes: ";
    cin >> m;

    int process[20];

    cout << "Enter process sizes:\n";
    for(int i = 0; i < m; i++)
        cin >> process[i];

    int start = 0;

    cout << "\nProcess\tBlock\n";

    for(int i = 0; i < m; i++)
    {
        int pos = -1;

        for(int j = 0; j < n; j++)
        {
            int k = (start + j) % n;

            if(block[k] >= process[i])
            {
                pos = k;
                break;
            }
        }

        if(pos != -1)
        {
            cout << "P" << i + 1 << "\tB" << pos + 1 << endl;

            block[pos] = block[pos] - process[i];

            start = pos;
        }
        else
        {
            cout << "P" << i + 1 << "\tNot Allocated\n";
        }
    }

    return 0;
}