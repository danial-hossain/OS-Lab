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

    for(int i = 0; i < f; i++)
        frame[i] = -1;

    int pos = 0;
    int fault = 0;

    for(int i = 0; i < n; i++)
    {
        bool found = false;

        for(int j = 0; j < f; j++)
        {
            if(frame[j] == page[i])
            {
                found = true;
                break;
            }
        }

        if(found == false)
        {
            frame[pos] = page[i];

            pos = (pos + 1) % f;

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