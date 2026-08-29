#include <iostream>
using namespace std;

int main()
{
    double temperature;
    int status;

    cout << "Enter temperature: ";
    cin >> temperature;

    // Find status code
    if (temperature < 0)
    {
        status = -1;
    }
    else if (temperature < 30)
    {
        status = 0;
    }
    else if (temperature < 45)
    {
        status = 1;
    }
    else if (temperature < 60)
    {
        status = 2;
    }
    else
    {
        status = 3;
    }

    // Print status and action
    switch (status)
    {
    case -1:
        cout << "Status : SENSOR_ERROR" << endl;
        cout << "Action : Sensor fault(Check Wiring)" << endl;
        break;

    case 0:
        cout << "Status : NORMAL" << endl;
        cout << "Action : No action required" << endl;
        break;

    case 1:
        cout << "Status : WARNING" << endl;
        cout << "Action : Alert " << endl;
        break;

    case 2:
        cout << "Status : CRITICAL" << endl;
        cout << "Action : system triggered" << endl;
        break;

    case 3:
        cout << "Status : SHUTDOWN" << endl;
        cout << "Action : Emergency shutdown " << endl;
        break;
    }

    cout << "Reading : "
         << (temperature >= 25 ? "Above Average" : "Below Average")
         << endl;

    double fahrenheit = (temperature * 9 / 5) + 32;

    cout << "Temperature : " << temperature
         << " C / " << fahrenheit << " F" << endl;

    return 0;
}