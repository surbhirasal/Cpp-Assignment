#include <iostream>
using namespace std;

int main()
{
    int N;

    cout << "Enter number of readings: ";
    cin >> N;

    double readings[100];

    // Step 1: Take readings
    for (int i = 0; i < N; i++)
    {
        cout << "Enter reading " << i << ": ";
        cin >> readings[i];
    }

    // Step 2: Print valid readings and count errors
    int errors = 0;

    cout << "\nValid readings : ";

    for (int i = 0; i < N; i++)
    {
        if (readings[i] < 0)
        {
            errors++;
            continue;
        }

        cout << readings[i] << " ";
    }

    cout << "\nSkipped (errors) : " << errors << endl;


    // Step 3: Find first reading >= 45
    for (int i = 0; i < N; i++)
    {
        if (readings[i] >= 45)
        {
            cout << "First CRITICAL : Index " << i
                 << " -> " << readings[i] << "°C" << endl;
            break;
        }
    }


    // Step 4: Find min, max and average in ONE loop
    double min = 0;
    double max = 0;
    double sum = 0;
    int validCount = 0;

    bool firstValid = true;

    for (int i = 0; i < N; i++)
    {
        if (readings[i] < 0)
        {
            continue;
        }

        if (firstValid)
        {
            min = readings[i];
            max = readings[i];
            firstValid = false;
        }

        if (readings[i] < min)
        {
            min = readings[i];
        }

        if (readings[i] > max)
        {
            max = readings[i];
        }

        sum = sum + readings[i];
        validCount++;
    }

    double average = sum / validCount;

    cout << "Min : " << min << "°C" << endl;
    cout << "Max : " << max << "°C" << endl;
    cout << "Avg : " << average << "°C" << endl;


    // Step 5: Count categories
    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    for (int i = 0; i < N; i++)
    {
        if (readings[i] < 0)
        {
            continue;
        }

        if (readings[i] < 30)
        {
            normal++;
        }
        else if (readings[i] < 45)
        {
            warning++;
        }
        else if (readings[i] < 60)
        {
            critical++;
        }
        else
        {
            shutdown++;
        }
    }

    cout << "Normal: " << normal << endl;
    cout << "Warning: " << warning << endl;
    cout << "Critical: " << critical << endl;
    cout << "Shutdown: " << shutdown << endl;

    return 0;
}