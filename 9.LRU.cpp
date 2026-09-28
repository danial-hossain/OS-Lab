#include <iostream>
using namespace std;

int main()
{
    int n, f;

    cout << "Enter number of pages: ";
    cin >> n;

    int page[50];

    cout << "Enter reference string: ";
    for(int i = 0; i < n; i++)
        cin >> page[i];

    cout << "Enter number of frames: ";
    cin >> f;

    int frame[20];
    int last[20];

    for(int i = 0; i < f; i++)
    {
        frame[i] = -1;
        last[i] = -1;
    }

    int fault = 0;

    for(int i = 0; i < n; i++)
    {
        bool found = false;

        for(int j = 0; j < f; j++)
        {
            if(frame[j] == page[i])
            {
                found = true;
                last[j] = i;
                break;
            }
        }

        if(found == false)
        {
            int pos = -1;

            for(int j = 0; j < f; j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
            {
                pos = 0;

                for(int j = 1; j < f; j++)
                {
                    if(last[j] < last[pos])
                        pos = j;
                }
            }

            frame[pos] = page[i];
            last[pos] = i;

            fault++;
        }

        cout << page[i] << " : ";

        for(int j = 0; j < f; j++)
            cout << frame[j] << " ";

        cout << endl;
    }

    cout << "\nPage Fault = " << fault;

    return 0;
}