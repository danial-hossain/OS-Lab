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

        if(found == false)//frame eine je box jeine process dhukhe
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
                int farthest = -1;

                for(int j = 0; j < f; j++)
                {
                    int k;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frame[j] == page[k])// just samne ekbar e check krbo,like optimal e jar positinon ta sobche kache
                            break;//oitai mattters,dure hoile oi jayga tai to nei
                    }

                    if(k == n)
                    {
                        pos = j;
                        break;
                    }

                    if(k > farthest)
                    {
                        farthest = k;
                        pos = j;
                    }
                }
            }

            frame[pos] = page[i];

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