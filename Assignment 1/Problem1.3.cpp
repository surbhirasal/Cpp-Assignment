
#include <iostream>
using namespace std;

int main()
{
    double temp[3][3];

    cout << "Enter temperatures:\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> temp[i][j];
        }
    }

    cout << "\nRoom1  Room2  Room3\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << temp[i][j] << "    ";
        }

        cout << endl;
    }

    double hottest = temp[0][0];
    int hotFloor = 0;
    int hotRoom = 0;

    int count = 0;

    double highestAverage = 0;
    int hottestFloor = 0;

    for (int i = 0; i < 3; i++)
    {
        double sum = 0;

        for (int j = 0; j < 3; j++)
        {
            if (temp[i][j] > hottest)
            {
                hottest = temp[i][j];
                hotFloor = i;
                hotRoom = j;
            }

            if (temp[i][j] >= 30)
            {
                count++;
            }

            sum = sum + temp[i][j];
        }

        double average = sum / 3;

        if (average > highestAverage)
        {
            highestAverage = average;
            hottestFloor = i;
        }
    }

    cout << "Hottest Room : Floor " << hotFloor + 1
         << ", Room " << hotRoom + 1
         << " -> " << hottest << " C" << endl;

    cout << "Hottest Floor : Floor " << hottestFloor + 1
         << " (avg " << highestAverage << " C)" << endl;

    cout << "Rooms at WARNING or above : " << count << endl;

    return 0;
}